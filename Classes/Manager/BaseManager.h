
#ifndef _BASE_MANAGER_H_
#define _BASE_MANAGER_H_

#include "cocos2d.h"
class BaseManager : public cocos2d::Ref
{
public:
	BaseManager();
	~BaseManager();

	virtual bool init();
};

#endif