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
	
	//��ʼ��view
	_view = ShopView::create();
	//��ʾview
	viewWillAppear(_view);

    return true;
}

void ShopController::menuStartGameCallback(Ref* pSender)
{

}