#include "MenuController.h"
#include "Manager\GameManager.h"
#include "Scene\GameScene.h"
USING_NS_CC;


bool MenuController::init()
{
    if ( !Layer::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"btnStart.png",
		"btnStartSel.png",
		CC_CALLBACK_1(MenuController::menuStartGameCallback, this));

	closeItem->setPosition(0, 0);
	//Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
	//                       origin.y + closeItem->getContentSize().height/2));

	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(menu, 1);

	auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2,
		origin.y + visibleSize.height - label->getContentSize().height));
	this->addChild(label, 1);

	auto sprite = Sprite::create("menuBG.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);

    return true;
}

void MenuController::menuStartGameCallback(Ref* pSender)
{
	GameScene* scene = GameScene::create();
	GameManager::getInstance()->sceneManager->replaceScene(scene);
}