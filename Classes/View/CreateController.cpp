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
	
	//��ʼ��view
	view = CreateView::create();
	//��ʾview
	viewWillAppear();

    return true;
}

void CreateController::menuStartGameCallback(Ref* pSender)
{

}