
#ifndef _BASE_DATA_ENTITY_H_
#define _BASE_DATA_ENTITY_H_

#include "cocos2d.h"

USING_NS_CC;

#define CREATE_FUNC_ID(__TYPE__) \
	bool __TYPE__::init(const Value& id) \
{ \
	dataId = id; \
	return true; \
} \
	static __TYPE__* create(const cocos2d::Value& id) \
{ \
	__TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
if (pRet && pRet->init(id)) \
{ \
	pRet->autorelease(); \
	return pRet; \
} \
	else \
{ \
	delete pRet; \
	pRet = NULL; \
	return NULL; \
} \
}

class BaseDataEntity : public cocos2d::Ref
{
public:
	//ÿ������ʵ�����涨�����и�id,���ɻ����������ȡ����ʱʹ��
	cocos2d::Value dataId;

public:
	BaseDataEntity();
	~BaseDataEntity();
	virtual bool init();
	//ʹ��id��ʼ������ʵ�� 
	virtual bool init(const Value& id);

	//ʹ��Դ���ݳ�ʼ��Dataʵ��
	virtual bool initWithData(const ValueMap& mapData);

	//������
	virtual bool bindingData(const ValueMap& mapData);
};

#endif