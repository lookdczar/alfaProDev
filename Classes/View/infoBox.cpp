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

	//��Ϣ���ʼ��
	VISIBLE_SIZE;
	_infoBox = Sprite::create("infoBox.png");
	Size contentSize = _infoBox->getContentSize();
	_infoBox->setAnchorPoint(Vec2(0.5, 0.5));
	_infoBox->setPosition(0, -visibleSize.height / 2 + 40 + contentSize.height / 2);
	_infoBox->setVisible(false);

	/*_infoBox->removeAllChildren();*/

	_closeButtom = Sprite::create("close.png");
	_closeButtom->setAnchorPoint(Vec2(0, 0));
	auto item1 = MenuItemSprite::create(_closeButtom, _closeButtom, _closeButtom, CC_CALLBACK_1(infoBox::hideInfoBox, this));
	_menu = Menu::create(item1, NULL);
	_menu->retain();
	_menu->setPosition(contentSize.width - 20, contentSize.height - 20);
	_infoBox->addChild(_menu);

	return true;
}

void infoBox::hideInfoBox(cocos2d::Object* pSender)
{
	_infoBox->setVisible(false);
}

void infoBox::resetInfoBox()
{
	_infoBox->removeAllChildren();
	_infoBox->addChild(_menu);
}
