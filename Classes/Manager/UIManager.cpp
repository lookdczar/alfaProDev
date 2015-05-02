#include "UIManager.h"

#define TABBARTAG 10000

UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

UIManager * UIManager::create(Layer * layer, ...)
{
	va_list args;
	va_start(args, layer);

	UIManager *uiManager = new (std::nothrow) UIManager();
	if (uiManager && uiManager->initWithLayers(layer, args))
	{
		uiManager->autorelease();
		va_end(args);
		return uiManager;
	}
	va_end(args);
	CC_SAFE_DELETE(uiManager);
	return nullptr;
}

bool UIManager::init()
{
	if (!Layer::init())
	{
		return false;
	}
}

bool UIManager::initWithLayers(Layer *layer, va_list params)
{
	if (!Layer::init())
	{
		return false;
	}
	_arrayOfLayers.reserve(5);
	_arrayOfLayers.pushBack(layer);
	Layer* l = va_arg(params, Layer*);
	while (l) {
		_arrayOfLayers.pushBack(l);
		l = va_arg(params, Layer*);
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (tabBarSize.height < 1.0)
	{
		tabBarSize.height = 40.0;
	}
	if (tabBarSize.width < 1.0)
	{
		tabBarSize.width = 320.0;
	}
	_tabBarBg = ui::Scale9Sprite::create("tabBarBg.png"); 
	_tabBarBg->setContentSize(tabBarSize);
	_tabBarBg->setCapInsets(CCRectMake(20.0, 9.5, 286.0, 21.5));
	_tabBarBg->setPosition(visibleSize.width * 0.5, tabBarSize.height*0.5);

	_layers = LayerMultiplex::createWithArray(_arrayOfLayers);
	_layers->setPosition(0.0, tabBarSize.height);
	this->addChild(_layers);

	this->addChild(_tabBarBg, 1000);

	auto toolbar1 = MenuItemSprite::create(Sprite::create("tabBarItem.png"), Sprite::create("tabBarItem_p.png"), CC_CALLBACK_1(UIManager::tapBarPressed, this));
	toolbar1->setTag(TABBARTAG + 0);

	auto toolbar2 = MenuItemSprite::create(Sprite::create("tabBarItem.png"), Sprite::create("tabBarItem_p.png"), CC_CALLBACK_1(UIManager::tapBarPressed, this));
	toolbar2->setTag(TABBARTAG + 1);

	auto toolbar3 = MenuItemSprite::create(Sprite::create("tabBarItem.png"), Sprite::create("tabBarItem_p.png"), CC_CALLBACK_1(UIManager::tapBarPressed, this));
	toolbar3->setTag(TABBARTAG + 2);

	auto toolbar4 = MenuItemSprite::create(Sprite::create("tabBarItem.png"), Sprite::create("tabBarItem_p.png"), CC_CALLBACK_1(UIManager::tapBarPressed, this));
	toolbar4->setTag(TABBARTAG + 3);

	auto toolbar5 = MenuItemSprite::create(Sprite::create("tabBarItem.png"), Sprite::create("tabBarItem_p.png"), CC_CALLBACK_1(UIManager::tapBarPressed, this));
	toolbar4->setTag(TABBARTAG + 4);

	_tabBar = Menu::create(toolbar1, toolbar2, toolbar3, toolbar4, toolbar5,NULL);
	_tabBar->alignItemsHorizontallyWithPadding(1);
	_tabBar->setAnchorPoint(Vec2(0.5,0.5));
	_tabBar->setPosition(visibleSize.width * 0.5, tabBarSize.height*0.5);
	_tabBarBg->addChild(_tabBar);
	CCLOG("%f,%f", _tabBar->getPosition().x , _tabBar->getPosition().y);
	return true;
}

void UIManager::tapBarPressed(Ref *pSender)
{
	auto toolbar = (MenuItemSprite *)pSender;
	toolbar->selected();
	_layers->switchTo(toolbar->getTag() - TABBARTAG);

	for (int i = 0; i < _tabBar->getChildren().size(); i++) {
		auto tmpbar = dynamic_cast<MenuItemSprite *>(_tabBar->getChildren().at(i));
		if (tmpbar != NULL && tmpbar->getTag() != toolbar->getTag()) {
			tmpbar->unselected();
		}
	}
}

void UIManager::onEnter()
{
	Layer::onEnter();
	_layers->switchTo(0);
	static_cast<MenuItemSprite *>(_tabBar->getChildByTag(TABBARTAG + 0))->selected();
}