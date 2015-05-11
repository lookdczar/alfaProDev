#include "BaseView.h"

USING_NS_CC;


bool BaseView::init()
{
	if (!Node::init())
		return false;
    
   //visibleSize = Director::getInstance()->getVisibleSize();
   //origin = Director::getInstance()->getVisibleOrigin();

    return true;
}
