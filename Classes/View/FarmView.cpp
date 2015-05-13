#include "FarmView.h"
#include "FarmController.h"
#include "Entity/FarmBuildData.h"

USING_NS_CC;


bool FarmView::init()
{
	if (!BaseView::init())
		return false;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("gameViewBg1.png");
	sprite->setPosition(0, 0);
	this->addChild(sprite, 0);

	return true;
}

void FarmView::showAdvArea(const cocos2d::Vector<FarmBuildData*>& buildInfos)
{
	Size	visibleSize =	Director::getInstance()->getVisibleSize();
	Vec2	origin = Director::getInstance()->getVisibleOrigin();

	int i = 0;
	for (auto Fbuild : buildInfos)
	{
		std::string name = Fbuild->buildImg.asString();
		auto sprite = Sprite::create(Fbuild->buildImg.asString());
		Size content = sprite->getContentSize();
		Vec2 po = Vec2(0, 0);
		sprite->setPosition(po);
		this->addChild(sprite);
		auto areaName = Label::createWithTTF(Fbuild->buildName.asString(), "fonts/Marker Felt.ttf", 24);
		areaName->setPosition(po.x, po.y - content.height / 2 - 12);
		this->addChild(areaName);

		i++;
	}
}
