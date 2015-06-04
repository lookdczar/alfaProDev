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
	//��Ϣ��
	infoBox* FinfoBox;

	FarmController* _Delegate;
public:
	FarmView();
	~FarmView();

	virtual bool init();

	CREATE_FUNC(FarmView);

	//��ʼ����Ϣ��
	void initinfoBox();
	//��ʾ������Ϣ
	void showFarmbuild(const cocos2d::Vector<FarmBuildData*>& buildInfos);
	//buildһ������
	void initFbuild(FarmBuildData* Fbuild, int i);

	void CDupdate(float delta, const cocos2d::Vector<FarmBuildData*>& buildInfos);
};

#endif 