#include "BaseView.h"

USING_NS_CC;


bool BaseView::init()
{
	if (!Node::init())
		return false;
    
   // Size visibleSize = Director::getInstance()->getVisibleSize();
   // Vec2 origin = Director::getInstance()->getVisibleOrigin();

    return true;
}
