#include "CreateController.h"
#include "CreateView.h"

USING_NS_CC;


bool CreateController::init()
{
    if ( !BaseController::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//≥ı ºªØview
	_view = CreateView::create();
	//œ‘ æview
	viewWillAppear(_view);

    return true;
}

void CreateController::menuStartGameCallback(Ref* pSender)
{

}