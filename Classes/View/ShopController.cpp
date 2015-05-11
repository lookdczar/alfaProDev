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
	_view = ShopView::create();
	//œ‘ æview
	viewWillAppear(_view);

    return true;
}

void ShopController::menuStartGameCallback(Ref* pSender)
{

}