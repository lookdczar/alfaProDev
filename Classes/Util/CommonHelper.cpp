#include "CommonHelper.h"


bool CommonHelper::ValueMapContainsKey(const cocos2d::ValueMap& map, const std::string& key)
{
	bool b = (map.find(key) != map.end());
	if (!b) CCLOG("map is not contains the key:%s",key.c_str());
	return b;
}