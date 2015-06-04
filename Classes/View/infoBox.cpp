#include "infoBox.h"
#include "Entity/ItemData.h"
#include "FarmController.h"

infoBox* infoBox::infobox = nullptr;

infoBox::infoBox()
{
}


infoBox::~infoBox()
{
	_menu->release();
}

infoBox* infoBox::getInstance()
{
	if (infobox == nullptr)
	{
		infobox = new infoBox;
		infobox->init();
	}
	return infobox;
}

void infoBox::destroyInstance()
{
	CC_SAFE_DELETE(infobox);
}

bool infoBox::init()
{
	if (!Sprite::init())
		return false;

	//信息框初始化
	VISIBLE_SIZE;
	_infoBox = Sprite::create("infoBox.png");
	Size contentSize = _infoBox->getContentSize();
	_infoBox->setAnchorPoint(Vec2(0.5, 0.5));
	_infoBox->setPosition(0, -visibleSize.height / 2 + 40 + contentSize.height / 2);
	_infoBox->setVisible(false);

	_closeButtom = Sprite::create("close.png");
	_closeButtom->setAnchorPoint(Vec2(0, 0));
	auto _item = MenuItemSprite::create(_closeButtom, _closeButtom, _closeButtom, CC_CALLBACK_1(infoBox::hideInfoBoxCallback, this));
	_menu = Menu::create(_item, NULL);
	_menu->retain();
	_menu->setPosition(contentSize.width - 20, contentSize.height - 20);
	_infoBox->addChild(_menu);

	return true;
}

void infoBox::hideInfoBoxCallback(cocos2d::Object* pSender)
{
	_infoBox->setVisible(false);
}

void infoBox::hideInfoBox()
{
	_infoBox->setVisible(false);
}

void infoBox::resetInfoBox()
{
	_infoBox->removeAllChildren();
	_infoBox->addChild(_menu);
}
