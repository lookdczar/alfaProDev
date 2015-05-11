#include "BaseDataEntity.h"


BaseDataEntity::BaseDataEntity()
{
}


BaseDataEntity::~BaseDataEntity()
{
}

bool BaseDataEntity::init()
{
	return true;
}

//使用id初始化数据实体 
bool BaseDataEntity::init(const Value& id)
{
	dataId = id;
	return true;
}

//使用源数据初始化Data实体
bool BaseDataEntity::initWithData(const  cocos2d::ValueMap& mapData)
{
	return true;
}

//绑定数据
bool BaseDataEntity::bindingData(const  cocos2d::ValueMap& mapData)
{
	return true;
}