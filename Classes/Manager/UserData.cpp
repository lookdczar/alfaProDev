#include "UserData.h"


UserData::UserData()
{

}

//使用map初始化
UserData* UserData::create(Value& value)
{
	UserData* pRet = new(std::nothrow) UserData();
	if (pRet && pRet->init(value))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}

UserData::~UserData()
{
}

bool UserData::init()
{
	return true;
}

bool UserData::init(Value& value)
{
	userData = value;
	return true;
}


