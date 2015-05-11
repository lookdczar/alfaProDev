
#ifndef _COMMON_UTIL_H_
#define _COMMON_UTIL_H_

#include "cocos2d.h"
#include "Config.h"

static class CommonHelper //: public cocos2d::Ref
{
public:
	//ValueMapÊÇ·ñ´æÔÚÄ³¸ökey
	static bool ValueMapContainsKey(const cocos2d::ValueMap& map,const std::string& key);

};

#endif