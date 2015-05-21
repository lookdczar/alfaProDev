#include "farmUI.h"
#include "Entity/ItemData.h"
#include "Entity/FarmBuildData.h"
#include "FarmController.h"
#include "infoBox.h"

cocos2d::Vector<FarmUI*> FarmUI::_farmUIs;
std::vector<int> FarmUI::_buildCDs;

FarmUI::FarmUI()
{
}


FarmUI::~FarmUI()
{
}

bool FarmUI::init()
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
	Size Boxsize = _buildBox->getContentSize();
	
	//建筑按钮初始化
	_buttom1 = Sprite::create("buttom1.png");
	_buttom1->setAnchorPoint(Vec2(0,0));
	_buttom2 = Sprite::create("buttom2.png");
	_buttom2->setAnchorPoint(Vec2(0,0));

	//采集CD条初始化
	_CDbar = LoadingBar::create("sliderProgress.png");
	_CDbar->setAnchorPoint(Vec2(0.5, 0.5));

	_CDcount = 0;
	//创建一个采集CD计时器
	auto scheduler = Director::getInstance()->getScheduler();
	scheduler->schedule(CC_CALLBACK_1(FarmUI::CDupdate, this), this, 0.01f, false, "WW");

	return true;
}

void FarmUI::InitBuildBox(FarmBuildData* Fbuild)
{
	VISIBLE_SIZE;
	Size Boxsize = _buildBox->getContentSize();

	//创建按钮菜单
	auto item1 = MenuItemSprite::create(_buttom1, _buttom1, NULL, CC_CALLBACK_1(FarmUI::fBuildCollect, this, this));
	auto item2 = MenuItemSprite::create(_buttom2, _buttom2, NULL, CC_CALLBACK_1(FarmUI::showInfoBox, this, Fbuild));
	auto menu = Menu::create(item1, item2, nullptr);
	menu->setPosition(4 * Boxsize.width / 5, Boxsize.height / 2);
	menu->alignItemsVertically();
	_buildBox->addChild(menu, 2);
	_buildBox->setTag(Fbuild->buildId.asInt());

	//CD条
	_CDbar->setTag(Fbuild->buildId.asInt());
	_CDbar->setPosition(Vec2(Boxsize.width / 2 - 20, Boxsize.height / 2 + 5));
	_buildBox->addChild(_CDbar, 2);

	_buildCDs.push_back(Fbuild->buildCD.asInt());
	_farmUIs.pushBack(this);

}


void FarmUI::showInfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild)
{
	auto FInfoBox = infoBox::getInstance();
	FInfoBox->resetInfoBox();
	auto Box = (Sprite*)FInfoBox->_infoBox;
	Size contentSize = Box->getContentSize();
	Box->setVisible(true);
	cocos2d::Vector<ItemData*> _itemInfos = FarmController::getitemInfos(Fbuild);
	int i = 0;
	for (auto item : _itemInfos)
	{
		std::string name = item->itemImg.asString();
		auto sprite = Sprite::create(name);
		sprite->setAnchorPoint(Vec2(0.5, 0.5));
		Box->addChild(sprite, 1);
		sprite->setPosition(30 + i * 35, contentSize.height / 2);
		sprite->setTag(i + 1);
		i++;
	}
}

void FarmUI::fBuildCollect(cocos2d::Object* pSender, FarmUI* FUI)
{
	
		if (FUI->_CDcount>100)
		{
			FUI->_CDcount = 0;
		}
}

void FarmUI::CDupdate(float delta)
{
	int i = 0;
	for (auto FUI : _farmUIs)
	{
		FUI->_CDcount += (100.0f * delta / _buildCDs[i]);
		FUI->_CDbar->setPercent(FUI->_CDcount);
		i++;
	}
}