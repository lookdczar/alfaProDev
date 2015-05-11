
#ifndef _BASE_MODEL_H_
#define _BASE_MODEL_H_

#include "cocos2d.h"
//#include "Manager\GameManager.h"
#include "Config.h"

//懒人宏 使用View初始化model，请先声明属性_view
#define CREATE_WITH_VIEW(__TYPE__,__VIEW_TYPE__) \
	static __TYPE__* create(__VIEW_TYPE__* view) \
{ \
	__TYPE__ *pRet = new(std::nothrow) __TYPE__(); \
if (pRet && pRet->init(view)) \
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

class BaseModel : public cocos2d::Ref
{
public:
	BaseModel();
	~BaseModel();

	virtual bool init();

};

#endif