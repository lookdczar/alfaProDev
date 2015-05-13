#include "FarmController.h"
#include "FarmView.h"
#include "model/FarmModel.h"

USING_NS_CC;


bool FarmController::init()
{
	if (!BaseController::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

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
	_view->showAdvArea(_model->_farmBuildInfos);

	//��ʾview
	viewWillAppear(_view);

	return true;
}

void FarmController::menuStartGameCallback(Ref* pSender)
{

}