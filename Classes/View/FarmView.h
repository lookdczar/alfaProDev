#ifndef __FARM_VIEW_H__
#define __FARM_VIEW_H__

#include "cocos2d.h"
#include "BaseView.h"

class FarmController;
class FarmBuildData;

class FarmView : public BaseView
{
public:
	//��Ϣ��
	cocos2d::Sprite*	_infoBox;
	//��Ϣ��رհ�ť
	cocos2d::Sprite*	_closeButtom;
	//����CD����ʱ
	float _count[2];
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
	//�ر���Ϣ��
	void hideinfoBox(cocos2d::Object* pSender);
	//ũ�������ɼ�����
	void fBuildCollect(cocos2d::Object* pSender);
	//CD������
	void CDupdate(float delta, const cocos2d::Vector<FarmBuildData*>& buildInfos);
};

#endif 