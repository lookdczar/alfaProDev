#ifndef __FARM_VIEW_H__
#define __FARM_VIEW_H__

#include "cocos2d.h"
#include "BaseView.h"

class FarmController;
class FarmBuildData;
class infoBox;

class FarmView : public BaseView
{
public:
	//信息框
	infoBox* FinfoBox;
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
	//农场建筑采集道具
	void fBuildCollect(cocos2d::Object* pSender);

	void CDupdate(float delta, const cocos2d::Vector<FarmBuildData*>& buildInfos);
};

#endif 