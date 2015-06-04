#include "farmUI.h"
#include "Entity/ItemData.h"
#include "Entity/FarmBuildData.h"
#include "FarmController.h"
#include "infoBox.h"
#include "Config.h"
#include "Manager/GameManager.h"
#include "../Util/GlobalConfig.h"

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

void FarmUI::InitBuildBox(FarmBuildData* Fbuild, FarmController* _Delegate)
{
	VISIBLE_SIZE;
	//buildBox初始化
	_buildBox = Sprite::create("buildBox.png");
	_buildBox->setAnchorPoint(Vec2(0.5, 0.5));
	Size Boxsize = _buildBox->getContentSize();

	//创建按钮菜单
	auto item1 = MenuItemSprite::create(_buttom1, _buttom1, NULL, CC_CALLBACK_1(FarmUI::fBuildCollect, this, Fbuild, this, _Delegate));
	auto item2 = MenuItemSprite::create(_buttom2, _buttom2, NULL, CC_CALLBACK_1(FarmUI::showInfoBox, this, Fbuild, _Delegate));
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


void FarmUI::showInfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmController* _Delegate)
{
	auto FInfoBox = infoBox::getInstance();
	FInfoBox->resetInfoBox();
	auto Box = (Sprite*)FInfoBox->_infoBox;
	Size BoxSize = Box->getContentSize();
	Box->setVisible(true);

	//创建升级按钮
	_buttom3 = Sprite::create("buttom3.png");
	auto item1 = MenuItemSprite::create(_buttom3, _buttom3, NULL, CC_CALLBACK_1(FarmUI::BuilldUpdate, this, Fbuild, _Delegate));
	auto menu1 = Menu::create(item1, NULL);
	Box->addChild(menu1);
	item1->setAnchorPoint(Vec2(0, 0));
	menu1->setAnchorPoint(Vec2(0, 0));
	menu1->setPosition(BoxSize.width - 60, 10);

	cocos2d::Vector<ItemData*> _itemInfos =_Delegate->getitemInfos(Fbuild);
	int i = 0;
	for (auto item : _itemInfos)
	{
		std::string name = item->itemName.asString();
		auto nameLabel = LabelTTF::create(name, "fonts/arial", 15);
		nameLabel->setAnchorPoint(Vec2(0, 0.5));
		Box->addChild(nameLabel);
		auto size = nameLabel->getContentSize();
		nameLabel->setPosition(10 + i, BoxSize.height - 20);
		i += (size.width + 10);
	}
// 	for (auto item : _itemInfos)
// 	{
// 		std::string name = item->itemImg.asString();
// 		auto sprite = Sprite::create(name);
// 		sprite->setAnchorPoint(Vec2(0.5, 0.5));
// 		Box->addChild(sprite, 1);
// 		sprite->setPosition(30 + i * 35, contentSize.height / 2);
// 		sprite->setTag(i + 1);
// 		i++;
// 	}
}

void FarmUI::fBuildCollect(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmUI* FUI, FarmController* _Delegate)
{
	//采集CD到，采集增加物品
	if (FUI->_CDcount > 100)
	{
		FUI->_CDcount = 0;
		ValueMap& ItemList = Fbuild->collections;
		//采集结果map
		ValueMap GainList = Fbuild->collections;
		for (auto item : GainList)
		{
			GainList[item.first] = 0;
		}
		//根据建筑物掉落均值决定物品掉落数量范围
		auto x = Fbuild->collectNum.asInt();
		auto collectNum = GlobalConfig::getRandom(x - 2, x + 2, true);
		//执行collectNum次循环
		for (auto k = 0; k < collectNum; k++)
		{
			auto RandNum = GlobalConfig::getRandom(1, 100, false);
			int i = 1;
			for (auto item : ItemList)
			{
				//100*几率
				auto Chance = int(100 * (item.second.asFloat()));
				if (i <= RandNum && RandNum < (i+Chance))
				{
					auto ItemID = (std::string)item.first;
					int itemCount = GET_MA_UDATA->getUserItemCount(ItemID).asInt();
					itemCount += 1;
					GET_MA_UDATA->setUserItemCount(ItemID, itemCount);
					GET_MA_UDATA->saveAllUserData();
					auto num = GainList[item.first].asInt();
					GainList[item.first] = num + 1;
				}
				i += Chance;
			}	
		}
		//弹框显示采集结果
		auto gainbox = GainBox::getInstance();
		gainbox->resetGainBox();
		auto Box = gainbox->_GainBox;
		auto BoxSize = Box->getContentSize();
		Box->setVisible(true);

		cocos2d::Vector<ItemData*> _itemInfos = _Delegate->getitemInfos(Fbuild);
		int j = 0;
		for (auto item : _itemInfos)
		{
			std::string itemid = item->itemId.asString();
			auto Num = GainList[itemid].asInt();
			if (Num != 0)
			{
				std::string name = item->itemName.asString();
				std::string NumString = Value(Num).asString();
				std::string str = name + "X" + NumString;
				auto nameLabel = LabelTTF::create(str, "fonts/arial", 15);
				nameLabel->setAnchorPoint(Vec2(0, 0.5));
				Box->addChild(nameLabel);
				auto size = nameLabel->getContentSize();
				nameLabel->setPosition(10 + j, BoxSize.height - 20);
				j += (size.width + 10);
			}
		}
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

void FarmUI::BuilldUpdate(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmController* _Delegate)
{
	auto BuildId = Fbuild->buildId.asInt();
	_Delegate->BuildUpdate(BuildId);
}


#pragma mark ----------GainBox函数----------

GainBox* GainBox::gainBox = nullptr;

GainBox::GainBox()
{

}

GainBox::~GainBox()
{
	_menu->release();
}

GainBox* GainBox::getInstance()
{
	if (gainBox == nullptr)
	{
		gainBox = new GainBox;
		gainBox->init();
	}
	return gainBox;
}

void GainBox::destroyInstance()
{
	CC_SAFE_DELETE(gainBox);
}


bool GainBox::init()
{
	if (!Sprite::init())
		return false;

	//信息框初始化
	VISIBLE_SIZE;
	_GainBox = Sprite::create("GainBox.png");
	Size contentSize = _GainBox->getContentSize();
	_GainBox->setAnchorPoint(Vec2(0.5, 0.5));
	_GainBox->setPosition(0,0);
	_GainBox->setVisible(false);

	_closeButtom = Sprite::create("close.png");
	_closeButtom->setAnchorPoint(Vec2(0, 0));
	auto _item = MenuItemSprite::create(_closeButtom, _closeButtom, _closeButtom, CC_CALLBACK_1(GainBox::hideGainBoxCallback, this));
	_menu = Menu::create(_item, NULL);
	_menu->retain();
	_menu->setPosition(contentSize.width - 20, contentSize.height - 20);
	_GainBox->addChild(_menu);

	return true;
}

void GainBox::hideGainBoxCallback(cocos2d::Object* pSender)
{
	_GainBox->setVisible(false);
}

void GainBox::hideGainBox()
{

}

void GainBox::resetGainBox()
{
	_GainBox->removeAllChildren();
	_GainBox->addChild(_menu);
}