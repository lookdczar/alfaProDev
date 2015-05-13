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
	_view->showAdvArea(_model->_farmBuildInfos);

	//显示view
	viewWillAppear(_view);

	return true;
}

void FarmController::menuStartGameCallback(Ref* pSender)
{

}