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

//ʹ��id��ʼ������ʵ�� 
bool BaseDataEntity::init(const Value& id)
{
	dataId = id;
	return true;
}

//ʹ��Դ���ݳ�ʼ��Dataʵ��
bool BaseDataEntity::initWithData(const  cocos2d::ValueMap& mapData)
{
	return true;
}

//������
bool BaseDataEntity::bindingData(const  cocos2d::ValueMap& mapData)
{
	return true;
}