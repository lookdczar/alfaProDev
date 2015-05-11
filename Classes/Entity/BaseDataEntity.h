
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
	//每个数据实体对象规定必须有个id,交由缓存管理器读取数据时使用
	cocos2d::Value dataId;

public:
	BaseDataEntity();
	~BaseDataEntity();
	virtual bool init();
	//使用id初始化数据实体 
	virtual bool init(const Value& id);

	//使用源数据初始化Data实体
	virtual bool initWithData(const ValueMap& mapData);

	//绑定数据
	virtual bool bindingData(const ValueMap& mapData);
};

#endif