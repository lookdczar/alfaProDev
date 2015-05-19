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

// 	//��������
// 	this->setTouchEnabled(true);
// 
// 	EventDispatcher* eventdispatcher = Director::getInstance()->getEventDispatcher();
// 
// 	auto	listener = EventListenerTouchOneByOne::create();
// 	listener->onTouchBegan = CC_CALLBACK_2(FarmController::onTouchBegan, this);
// 	listener->onTouchMoved = CC_CALLBACK_2(FarmController::onTouchMoved, this);
// 	listener->onTouchEnded = CC_CALLBACK_2(FarmController::onTouchEnded, this);
// 	eventdispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//��ʼ��view
	_view = FarmView::create();
	//��ʼ��model
	_model = FarmModel::create(_view);
	_model->retain();

	//��ȡ�Ѿ���������ID
	_model->getUserDataAndInitInfos();
	//��ȡ��������������Ϣ
	_model->getDetailInfos();
	//�ó�����ʾ
	_view->showFarmbuild(_model->_farmBuildInfos);

	//��ʾview
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
