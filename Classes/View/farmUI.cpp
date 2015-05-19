#include "farmUI.h"


farmUI::farmUI()
{
}


farmUI::~farmUI()
{
}

bool farmUI::init()
{
	if (!Node::init())
	{
		return false;
	}

	Size	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2	origin = Director::getInstance()->getVisibleOrigin();

	//buildBox初始化
	_buildBox = Sprite::create("buildBox.png");
	_buildBox->setAnchorPoint(Vec2(0.5, 0.5));
	
	//建筑按钮初始化
	_buttom1 = Sprite::create("buttom1.png");
	_buttom1->setAnchorPoint(Vec2(0,0));
	_buttom2 = Sprite::create("buttom2.png");
	_buttom2->setAnchorPoint(Vec2(0,0));

	//采集CD条初始化
	_CDbar = LoadingBar::create("sliderProgress.png");
	_CDbar->setAnchorPoint(Vec2(0.5, 0.5));

	return true;
}

