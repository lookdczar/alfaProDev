#ifndef __CREATE_CONTROLLER_H__
#define __CREATE_CONTROLLER_H__

#include "cocos2d.h"
#include "BaseController.h"

class CreateView;

class CreateController : public BaseController
{
public:
	CreateView* _view;

public:

    virtual bool init();

	void menuStartGameCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(CreateController);

	
};

#endif 
