#include "AdvController.h"
#include "AdvView.h"
#include "Model\AdvModel.h"

USING_NS_CC;

AdvController::AdvController()
{
}


AdvController::~AdvController()
{
	CC_SAFE_RELEASE(_model);
}

bool AdvController::init()
{
    if ( !BaseController::init() )
    {
        return false;
    }

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	//初始化view
	_view = AdvView::create();
	//初始化model
	_model = AdvModel::create(_view);
	_model->retain();

	//获取已经解锁场景ID
	_model->getUserDataAndInitInfos();
	//获取解锁场景具体信息
	_model->getDetailInfos();
	//让场景显示
	_view->showAdvArea(_model->_advAreaInfos);

	//显示view
	viewWillAppear(_view);

    return true;
}

void AdvController::menuStartGameCallback(Ref* pSender)
{

}