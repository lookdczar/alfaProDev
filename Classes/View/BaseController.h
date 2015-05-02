#ifndef __BASE_CONTROLLER_H__
#define __BASE_CONTROLLER_H__

#include "cocos2d.h"
#include "BaseView.h"

class BaseController : public cocos2d::Layer
{
public:
	BaseView* view;

public:

    virtual bool init();

protected:
	void viewWillAppear();


};

#endif 
