
#ifndef _USER_DATA_H_
#define _USER_DATA_H_

#include "cocos2d.h"

USING_NS_CC;

//某项用户数据，一种数据（如已解锁冒险场景）为一个数据（UserData)
class UserData : public cocos2d::Ref
{
public:

	//具体用户数据
	cocos2d::Value userData;

	//已解锁冒险场景
//	cocos2d::ValueVector advUnlocked;

public:
	UserData();
	~UserData();

	virtual bool init();
	virtual bool init(Value& value);

	CREATE_FUNC(UserData);
	//使用map初始化
	static UserData* create(Value& value);

};

#endif