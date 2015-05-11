#include "FileHelper.h"


USING_NS_CC;

//保存plist
bool FileHelper::plistWriteFile(const cocos2d::ValueMap& map, const std::string& filePath)
{
	std::string file = cocos2d::FileUtils::getInstance()->getWritablePath() + filePath;

	tinyxml2::XMLDocument* pDoc = new tinyxml2::XMLDocument();

	XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
	pDoc->LinkEndChild(pDel);

	//添加plist节点
	XMLElement *plistElement = pDoc->NewElement("plist");
	plistElement->SetAttribute("version", "1.0");
	pDoc->LinkEndChild(plistElement);
	//添加dic节点
	XMLElement *dicElement = pDoc->NewElement("dic");
	for (auto v : map)
	{
		plistWriteNode(v.first, v.second, dicElement, pDoc, true);
	}
	plistElement->LinkEndChild(dicElement);

#ifdef DEV_STATUS
	XMLError errorID = pDoc->SaveFile(filePath.c_str());
#else
	XMLError errorID = pDoc->SaveFile(file.c_str());
#endif

	delete pDoc;

	if (errorID != 0) {
		CCLOG("Parse Error!");
		return false;
	}
	return true;
}

bool FileHelper::plistWriteNode(const std::string& key,
								const cocos2d::Value& value, 
								XMLElement* parentNode,
								tinyxml2::XMLDocument* pDoc,
								bool isDic)
{

	std::string tempStr;

	if (value.getType() == Value::Type::BOOLEAN)
	{
		if (isDic)
		{
			XMLElement *keyElement = pDoc->NewElement("key");
			keyElement->LinkEndChild(pDoc->NewText(key.c_str()));
			parentNode->LinkEndChild(keyElement);
		}
		if (value.asBool())
		{
			parentNode->LinkEndChild(pDoc->NewElement("true"));
		}
		else
			parentNode->LinkEndChild(pDoc->NewElement("false"));
		return true;
	}
	if (value.getType() == Value::Type::INTEGER)
	{
		if (isDic)
		{
			XMLElement *keyElement = pDoc->NewElement("key");
			keyElement->LinkEndChild(pDoc->NewText(key.c_str()));
			parentNode->LinkEndChild(keyElement);
		}
		XMLElement *valueElement = pDoc->NewElement("integer");
		tempStr = value.asString();
		valueElement->LinkEndChild(pDoc->NewText(tempStr.c_str()));
		parentNode->LinkEndChild(valueElement);
		return true;
	}
	if (value.getType() == Value::Type::DOUBLE)
	{
		if (isDic)
		{
			XMLElement *keyElement = pDoc->NewElement("key");
			keyElement->LinkEndChild(pDoc->NewText(key.c_str()));
			parentNode->LinkEndChild(keyElement);
		}
		XMLElement *valueElement = pDoc->NewElement("real");
		tempStr = value.asString();
		valueElement->LinkEndChild(pDoc->NewText(tempStr.c_str()));
		parentNode->LinkEndChild(valueElement);
		return true;
	}
	if (value.getType() == Value::Type::STRING)
	{
		if (isDic)
		{
			XMLElement *keyElement = pDoc->NewElement("key");
			keyElement->LinkEndChild(pDoc->NewText(key.c_str()));
			parentNode->LinkEndChild(keyElement);
		}
		XMLElement *valueElement = pDoc->NewElement("string");
		tempStr = value.asString();
		valueElement->LinkEndChild(pDoc->NewText(tempStr.c_str()));
		parentNode->LinkEndChild(valueElement);
		return true;
	}
	if (value.getType() == Value::Type::MAP)
	{
		XMLElement *keyElement = pDoc->NewElement("key");
		keyElement->LinkEndChild(pDoc->NewText(key.c_str()));
		parentNode->LinkEndChild(keyElement);
		XMLElement *valueElement = pDoc->NewElement("dic");
		for (auto v : value.asValueMap())
		{
			plistWriteNode(v.first, v.second, valueElement, pDoc,true);
		}
		parentNode->LinkEndChild(valueElement);
		return true;
	}
	if (value.getType() == Value::Type::VECTOR)
	{
		XMLElement *keyElement = pDoc->NewElement("key");
		keyElement->LinkEndChild(pDoc->NewText(key.c_str()));
		parentNode->LinkEndChild(keyElement);
		XMLElement *valueElement = pDoc->NewElement("array");
		for (auto v : value.asValueVector())
		{
			plistWriteNode("", v, valueElement, pDoc, false);
		}
		parentNode->LinkEndChild(valueElement);
		return true;
	}
}