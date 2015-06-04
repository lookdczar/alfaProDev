#include "FarmController.h"
#include "FarmView.h"
#include "model/FarmModel.h"
#include "model/ItemModel.h"
#include "farmUI.h"
#include "infoBox.h"

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
	_view->retain();
	_view->_Delegate = this;

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

void FarmController::BuildUpdate(int buildid)
{
	infoBox::getInstance()->hideInfoBox();
	_view->removeChildByTag(buildid,true);
	_model->setbuildUnlock(buildid);
	//��ȡ�ѽ�����ũ������ID
	Value&	vId = GET_MA_UDATA->getUserData(USER_DATA_TYPE::buildUnlocked);
	ValueVector &arrId = vId.asValueVector();

	auto BuildNum = _model->_farmBuildInfos.size();

	_model->_farmBuildInfos.replace(buildid - 1, FarmBuildData::create(Value(arrId[buildid % BuildNum - 1])));
	//��ȡ��������������Ϣ
	_model->getDetailInfos();

	cocos2d::Vector<FarmBuildData*>& buildInfos = _model->_farmBuildInfos;

	for (auto Fbuild : _model->_farmBuildInfos)
	{
		//�ж��ĸ���������
		if (Fbuild->buildId.asInt() % BuildNum == buildid % BuildNum)
		{
			_view->initFbuild(Fbuild, buildid % BuildNum - 1);
			//ɾ������ǰ��FarmUI,�����������FarmUI
			auto i = FarmUI::_farmUIs.size();
			FarmUI::_farmUIs.swap(buildid % BuildNum - 1, i-1);
			FarmUI::_farmUIs.erase(i - 1);
		}
	}
	//�ó�����ʾ
	/*_view->showFarmbuild(_model->_farmBuildInfos);*/
}
