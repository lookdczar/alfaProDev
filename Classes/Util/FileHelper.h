
#ifndef _FILE_HELPER_H_
#define _FILE_HELPER_H_

#include "cocos2d.h"
#include "Config.h"
#include "tinyxml2\tinyxml2.h"

using namespace tinyxml2;

static class FileHelper //: public cocos2d::Ref
{

private:
	//将内容添加到plist中的某个父节点
	static bool plistWriteNode(const std::string& key,
							   const cocos2d::Value& value,
							   tinyxml2::XMLElement* parentNode,
							   tinyxml2::XMLDocument* pDoc,
							   bool isDic);
public:
	//保存plist
	static bool plistWriteFile(const cocos2d::ValueMap& map,const std::string& filePath);

};

#endif