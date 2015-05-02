#ifndef __MENU_CONTROLLER_H__
#define __MENU_CONTROLLER_H__

#include "cocos2d.h"
#include "BaseController.h"

class MenuController : public BaseController
{
public:

    virtual bool init();

	void menuStartGameCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(MenuController);
};

#endif 
