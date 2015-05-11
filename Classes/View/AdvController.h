#ifndef __ADV_CONTROLLER_H__
#define __ADV_CONTROLLER_H__

#include "cocos2d.h"
#include "BaseController.h"

class AdvModel;
class AdvView;

class AdvController : public BaseController
{
public:
	AdvModel* _model;
	AdvView* _view;

public:
	AdvController();
	~AdvController();
    virtual bool init();

	void menuStartGameCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(AdvController);
};

#endif 
