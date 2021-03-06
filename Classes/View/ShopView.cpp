#include "ShopView.h"

USING_NS_CC;


bool ShopView::init()
{
	if (!BaseView::init())
		return false;

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("gameViewBg0.png");
	sprite->setPosition(0,0);
	this->addChild(sprite, 0);

    return true;
}
