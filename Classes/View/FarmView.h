#ifndef __FARM_VIEW_H__
#define __FARM_VIEW_H__

#include "cocos2d.h"
#include "BaseView.h"

class FarmController;
class FarmBuildData;

class FarmView : public BaseView
{
public:
	//信息框
	cocos2d::Sprite*	_infoBox;
	//信息框关闭按钮
	cocos2d::Sprite*	_closeButtom;
	//用于CD条计时
	float _count[2];
public:
	FarmView();
	~FarmView();

	virtual bool init();

	CREATE_FUNC(FarmView);

	//初始化信息框
	void initinfoBox();
	//显示场景信息
	void showFarmbuild(const cocos2d::Vector<FarmBuildData*>& buildInfos);
	//按下按钮显示信息框
	void showinfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild);
	//关闭信息框
	void hideinfoBox(cocos2d::Object* pSender);
	//农场建筑采集道具
	void fBuildCollect(cocos2d::Object* pSender);
	//CD条更新
	void CDupdate(float delta, const cocos2d::Vector<FarmBuildData*>& buildInfos);
};

#endif 