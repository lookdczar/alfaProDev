#include "UserData.h"


UserData::UserData()
{

}

//ʹ��map��ʼ��
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


