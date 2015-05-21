#include "FarmView.h"
#include "FarmController.h"
#include "Entity/FarmBuildData.h"
#include "Entity/ItemData.h"
#include "View/farmUI.h"
#include "Config.h"
#include "infoBox.h"

USING_NS_CC;

FarmView::FarmView()
{
	
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

	auto FInfoBox = infoBox::getInstance();
	this->addChild(FInfoBox->_infoBox);

	return true;
}

void FarmView::showFarmbuild(const cocos2d::Vector<FarmBuildData*>& buildInfos)
{
	Size	visibleSize =	Director::getInstance()->getVisibleSize();
	Vec2	origin = Director::getInstance()->getVisibleOrigin();

	int i = 0;
	for (auto Fbuild : buildInfos)
	{
		std::string name = Fbuild->buildImg.asString();
		auto sprite = Sprite::create(name);
		sprite->setAnchorPoint(Vec2(0, 0));

		//创建一个建筑框
		auto buildBox = FarmUI::create();
		buildBox->InitBuildBox(Fbuild);
		Size Boxsize = buildBox->_buildBox->getContentSize();
		buildBox->_buildBox->setPosition(0, visibleSize.height / 2 - (2 * i + 1) * Boxsize.height / 2 - 20);
		
		//将建筑加入建筑框
		buildBox->_buildBox->addChild(sprite, 1);
		sprite->setPosition(10, 15);

		this->addChild(buildBox->_buildBox);

		i++;
	}
}
// 
// void FarmView::showinfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild)
// {
// 	auto Box = (Sprite*)FinfoBox->_infoBox;
// 	Size contentSize = Box->getContentSize();
// 	Box->setVisible(true);
// 	cocos2d::Vector<ItemData*> _itemInfos = FarmController::getitemInfos(Fbuild);
// 	int i = 0;
// 	for (auto item : _itemInfos)
// 	{
// 		std::string name = item->itemImg.asString();
// 		auto sprite = Sprite::create(name);
// 		sprite->setAnchorPoint(Vec2(0.5,0.5));
// 		Box->addChild(sprite, 1);
// 		sprite->setPosition(30 + i * 35, contentSize.height / 2);
// 		sprite->setTag(i + 1);
// 		i++;
// 	}
// }
// 
// void FarmView::fBuildCollect(cocos2d::Object* pSender)
// {
// 	for (int i = 0; i < 2; i++)
// 	{
// 		if (_count[i] > 100)
// 		{
// 			_count[i] = 0;
// 		}
// 	}
// }
// 
// void FarmView::CDupdate(float delta, const cocos2d::Vector<FarmBuildData*>& buildInfos)
// {
// 	for (auto Fbuild : buildInfos)
// 	{
// 		Sprite* buildBox = static_cast<Sprite*>(this->getChildByTag(Fbuild->buildId.asInt()));
// 		LoadingBar* loadingBar = static_cast<LoadingBar*>(buildBox->getChildByTag(Fbuild->buildId.asInt()));
// 		float CD = Fbuild->buildCD.asFloat();
// 		float CDNow = 
// 		//每个建筑CD不同进度条速度不同
// 		_count[i] += (100.0 * delta / CD);
// 		loadingBar->setPercent(_count[i]);
// 	}
// }


