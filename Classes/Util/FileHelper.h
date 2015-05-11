
#ifndef _FILE_HELPER_H_
#define _FILE_HELPER_H_

#include "cocos2d.h"
#include "Config.h"
#include "tinyxml2\tinyxml2.h"

using namespace tinyxml2;

static class FileHelper //: public cocos2d::Ref
{

private:
	//��������ӵ�plist�е�ĳ�����ڵ�
	static bool plistWriteNode(const std::string& key,
							   const cocos2d::Value& value,
							   tinyxml2::XMLElement* parentNode,
							   tinyxml2::XMLDocument* pDoc,
							   bool isDic);
public:
	//����plist
	static bool plistWriteFile(const cocos2d::ValueMap& map,const std::string& filePath);

};

#endif