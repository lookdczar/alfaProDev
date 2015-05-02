#include "BaseController.h"

USING_NS_CC;


bool BaseController::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
   // Size visibleSize = Director::getInstance()->getVisibleSize();
   // Vec2 origin = Director::getInstance()->getVisibleOrigin();

    return true;
}

void BaseController::viewWillAppear()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (!view || view == nullptr)
		return;

		view->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		addChild(view);

}
