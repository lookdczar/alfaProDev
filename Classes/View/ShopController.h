#ifndef __SHOP_CONTROLLER_H__
#define __SHOP_CONTROLLER_H__

#include "cocos2d.h"
#include "BaseController.h"

class ShopView;

class ShopController : public BaseController
{
public:
	ShopView* _view;

public:

    virtual bool init();

	void menuStartGameCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(ShopController);

};

#endif 
