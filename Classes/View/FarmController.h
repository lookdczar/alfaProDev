#ifndef __FARM_CONTROLLER_H__
#define __FARM_CONTROLLER_H__

#include "cocos2d.h"
#include "BaseController.h"

class FarmModel;
class FarmView;

class FarmController : public BaseController
{
public:
	FarmView* _view;
	FarmModel*	_model;

public:
	virtual bool init();

	void menuStartGameCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(FarmController);
};

#endif 