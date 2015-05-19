#include "FarmController.h"
#include "FarmView.h"
#include "model/FarmModel.h"
#include "model/ItemModel.h"

USING_NS_CC;


bool FarmController::init()
{
	if (!BaseController::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

// 	//开启触摸
// 	this->setTouchEnabled(true);
// 
// 	EventDispatcher* eventdispatcher = Director::getInstance()->getEventDispatcher();
// 
// 	auto	listener = EventListenerTouchOneByOne::create();
// 	listener->onTouchBegan = CC_CALLBACK_2(FarmController::onTouchBegan, this);
// 	listener->onTouchMoved = CC_CALLBACK_2(FarmController::onTouchMoved, this);
// 	listener->onTouchEnded = CC_CALLBACK_2(FarmController::onTouchEnded, this);
// 	eventdispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//初始化view
	_view = FarmView::create();
	//初始化model
	_model = FarmModel::create(_view);
	_model->retain();

	//获取已经解锁场景ID
	_model->getUserDataAndInitInfos();
	//获取解锁场景具体信息
	_model->getDetailInfos();
	//让场景显示
	_view->showFarmbuild(_model->_farmBuildInfos);

	//显示view
	viewWillAppear(_view);

	return true;
}

void FarmController::menuStartGameCallback(Ref* pSender)
{

}

cocos2d::Vector<ItemData*> FarmController::getitemInfos(FarmBuildData* Fbuild)
{
	ValueMap& itemlist = Fbuild->collections;
	auto _imodel = ItemModel::create();
	_imodel->getIteminfosBymap(itemlist);
	cocos2d::Vector<ItemData*> _itemInfos = _imodel->getDetailInfos();

	return _itemInfos;
}
