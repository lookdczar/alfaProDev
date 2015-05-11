#include "AdvView.h"
#include "AdvController.h"
#include "Entity\AdvAreaData.h"
USING_NS_CC;


bool AdvView::init()
{
	if (!BaseView::init())
		return false;

	auto sprite = Sprite::create("gameViewBg0.png");
	sprite->setPosition(0,0);
	this->addChild(sprite, 0);

	//controller = dynamic_cast<AdvController*>(this->getParent());

    return true;
}

//显示场景信息
void AdvView::showAdvArea(const cocos2d::Vector<AdvAreaData*>& advInfos)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	int i = 0;
	for (auto area : advInfos)
	{
		std::string name = area->areaImg.asString();
		auto sprite = Sprite::create(area->areaImg.asString());
		Size content = sprite->getContentSize();
		Vec2 po = Vec2(-visibleSize.width / 2 + content.width / 2, visibleSize.height / 2 - content.height/2 -i*(content.height+23)-20 );
		sprite->setPosition(po);
		this->addChild(sprite);

		auto areaName = Label::createWithTTF(area->areaName.asString(), "fonts/Marker Felt.ttf", 24);
		areaName->setPosition(po.x, po.y - content.height / 2-12);
		this->addChild(areaName);

		i++;
	}
}
