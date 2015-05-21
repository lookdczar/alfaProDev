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
public:
	FarmView();
	~FarmView();

	virtual bool init();

	CREATE_FUNC(FarmView);

	//��ʼ����Ϣ��
	void initinfoBox();
	//��ʾ������Ϣ
	void showFarmbuild(const cocos2d::Vector<FarmBuildData*>& buildInfos);
	//���°�ť��ʾ��Ϣ��
	void showinfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild);
	//ũ�������ɼ�����
	void fBuildCollect(cocos2d::Object* pSender);

	void CDupdate(float delta, const cocos2d::Vector<FarmBuildData*>& buildInfos);
};

#endif 