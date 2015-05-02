#include "ShopController.h"
#include "ShopView.h"

USING_NS_CC;


bool ShopController::init()
{
    if ( !BaseController::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//≥ı ºªØview
	view = ShopView::create();
	//œ‘ æview
	viewWillAppear();

    return true;
}

void ShopController::menuStartGameCallback(Ref* pSender)
{

}