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

	auto sprite = Sprite::create("Farmbg.png");
	sprite->setPosition(0, 0);
	this->addChild(sprite, 0);

	auto FInfoBox = infoBox::getInstance();
	this->addChild(FInfoBox->_infoBox , 2);

	auto FGainBox = GainBox::getInstance();
	this->addChild(FGainBox->_GainBox, 2);

	return true;
}

void FarmView::showFarmbuild(const cocos2d::Vector<FarmBuildData*>& buildInfos)
{
	int i = 0;
	for (auto Fbuild : buildInfos)
	{
		initFbuild(Fbuild, i);
		i++;
	}
}

void FarmView::initFbuild(FarmBuildData* Fbuild, int i)
{
	Size	visibleSize = Director::getInstance()->getVisibleSize();
	Vec2	origin = Director::getInstance()->getVisibleOrigin();

	std::string imgname = Fbuild->buildImg.asString();
	auto sprite = Sprite::create(imgname);
	sprite->setAnchorPoint(Vec2(0.5, 0.5));

	//获取建筑名称
	std::string buildname = Fbuild->buildName.asString();
	auto name = LabelTTF::create(buildname, "fonts/arial", 15);
	name->setAnchorPoint(Vec2(0, 0));

	//创建一个建筑框
	auto buildBox = FarmUI::create();
	buildBox->InitBuildBox(Fbuild, _Delegate);
	Size Boxsize = buildBox->_buildBox->getContentSize();
	buildBox->_buildBox->setPosition(0, visibleSize.height / 2 - (2 * i + 1) * Boxsize.height / 2 - 20);

	//将建筑加入建筑框
	buildBox->_buildBox->addChild(sprite, 1);
	sprite->setPosition(35, Boxsize.height / 2);

	buildBox->_buildBox->addChild(name);
	name->setPosition(Boxsize.width / 5, 15);
	name->setColor(Color3B(0, 0, 0));

	this->addChild(buildBox->_buildBox, 1);
	buildBox->_buildBox->setTag(Fbuild->buildId.asInt());
}



