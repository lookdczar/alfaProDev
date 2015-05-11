
#ifndef _USER_DATA_MANAGER_H_
#define _USER_DATA_MANAGER_H_

#include "cocos2d.h"
#include "BaseManager.h"
#include "UserData.h"

class UserDataManager : public BaseManager
{

private:
	//所有用户数据的容器，一种数据（如已解锁冒险场景）为一个数据（UserData)
	cocos2d::Map<std::string, UserData*> allData;

public:
	UserDataManager();
	~UserDataManager();

	virtual bool init();

	//获取已解锁冒险场景编号
	UserData* getAdvUnlockedInfo();

	//获取某个用户数据
	cocos2d::Value getUserData(USER_DATA_TYPE type);

	//保存当前用户数据
	bool saveAllUserData();
};

#endif