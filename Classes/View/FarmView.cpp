#include "FarmView.h"
#include "FarmController.h"
#include "Entity/FarmBuildData.h"
#include "Entity/ItemData.h"
#include "View/farmUI.h"
#include "Config.h"

USING_NS_CC;

FarmView::FarmView()
{
	for (int i = 0; i < 2;i++)
	{
		_count[i] = 0;
	}
}

FarmView::~FarmView()
{
	unscheduleUpdate();
}

bool FarmView::init()
{
	if (!BaseView::init())
		return false;

	auto sprite = Sprite::create("gameViewBg1.png");
	sprite->setPosition(0, 0);
	this->addChild(sprite, 0);

	initinfoBox();

	return true;
}

void FarmView::showFarmbuild(const cocos2d::Vector<FarmBuildData*>& buildInfos)
{
	Size	visibleSize =	Director::getInstance()->getVisibleSize();
	Vec2	origin = Director::getInstance()->getVisibleOrigin();
	
	//创建一个采集CD计时器
	auto scheduler = Director::getInstance()->getScheduler();
	scheduler->schedule(CC_CALLBACK_1(FarmView::CDupdate, this, buildInfos), this, 0.01f, false,"WW");

	int i = 0;
	for (auto Fbuild : buildInfos)
	{
		std::string name = Fbuild->buildImg.asString();
		auto sprite = Sprite::create(name);
		sprite->setAnchorPoint(Vec2(0, 0));
		/*Size content = sprite->getContentSize();*/

		//创建一个建筑框
		auto buildBox = farmUI::create();
		Size Boxsize = buildBox->_buildBox->getContentSize();
		buildBox->_buildBox->setPosition(0, visibleSize.height / 2 - (2 * i + 1) * Boxsize.height / 2 - 20);
		buildBox->_buildBox->setTag(Fbuild->buildId.asInt());
		
		//将建筑加入建筑框
		buildBox->_buildBox->addChild(sprite, 1);
		sprite->setPosition(10, 15);
		
		//创建按钮菜单
		auto item1 = MenuItemSprite::create(buildBox->_buttom1, buildBox->_buttom1,NULL,CC_CALLBACK_1(FarmView::fBuildCollect, this));
		auto item2 = MenuItemSprite::create(buildBox->_buttom2, buildBox->_buttom2, NULL, CC_CALLBACK_1(FarmView::showinfoBox, this, Fbuild));
		auto menu = Menu::create(item1, item2, nullptr);
		menu->setPosition(4 * Boxsize.width/5 , Boxsize.height/2);
		menu->alignItemsVertically();
		buildBox->_buildBox->addChild(menu, 2);

		//CD条
		buildBox->_CDbar->setTag(Fbuild->buildId.asInt());
		buildBox->_CDbar->setPosition(Vec2(Boxsize.width / 2-20, Boxsize.height / 2+5));
		buildBox->_buildBox->addChild(buildBox->_CDbar,2);

		this->addChild(buildBox->_buildBox);

		i++;
	}
}

void FarmView::initinfoBox()
{
	//信息框初始化
	VISIBLE_SIZE;
	_infoBox = Sprite::create("infoBox.png");
	Size contentSize = _infoBox->getContentSize();
	_infoBox->setAnchorPoint(Vec2(0.5, 0.5));
	_infoBox->setPosition(0, -visibleSize.height / 2 + 40 + contentSize.height / 2);
	_infoBox->setVisible(false);

	_closeButtom = Sprite::create("close.png");
	_closeButtom->setAnchorPoint(Vec2(0, 0));
	auto item1 = MenuItemSprite::create(_closeButtom, _closeButtom, _closeButtom, CC_CALLBACK_1(FarmView::hideinfoBox, this));
	auto menu = Menu::create(item1, NULL);
	menu->setPosition(contentSize.width - 20, contentSize.height - 20);
	_infoBox->addChild(menu);
	this->addChild(_infoBox);
}

void FarmView::showinfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild)
{
	Size contentSize = _infoBox->getContentSize();
	_infoBox->setVisible(true);
	cocos2d::Vector<ItemData*> _itemInfos = FarmController::getitemInfos(Fbuild);
	int i = 0;
	for (auto item : _itemInfos)
	{
		std::string name = item->itemImg.asString();
		auto sprite = Sprite::create(name);
		sprite->setAnchorPoint(Vec2(0.5,0.5));
		_infoBox->addChild(sprite, 1);
		sprite->setPosition(30 + i * 35, contentSize.height / 2);
		sprite->setTag(i + 1);
		i++;
	}
}

void FarmView::hideinfoBox(cocos2d::Object* pSender)
{
	_infoBox->setVisible(false);
	for (int i = 1; i < 10; i++)
	{
		_infoBox->removeChildByTag(i);
	}

}

void FarmView::fBuildCollect(cocos2d::Object* pSender)
{
	for (int i = 0; i < 2; i++)
	{
		if (_count[i] > 100)
		{
			_count[i] = 0;
		}
	}
}

void FarmView::CDupdate(float delta, const cocos2d::Vector<FarmBuildData*>& buildInfos)
{
	int i = 0;
	for (auto Fbuild : buildInfos)
	{
		Sprite* buildBox = static_cast<Sprite*>(this->getChildByTag(Fbuild->buildId.asInt()));
		LoadingBar* loadingBar = static_cast<LoadingBar*>(buildBox->getChildByTag(Fbuild->buildId.asInt()));
		float CD = Fbuild->buildCD.asFloat();
		//每个建筑CD不同进度条不同
		_count[i] += (100.0 * delta / CD);
		loadingBar->setPercent(_count[i]);
		i++;
	}
}


