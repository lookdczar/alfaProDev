
#ifndef _ADV_MODEL_H_
#define _ADV_MODEL_H_

#include "cocos2d.h"
#include "Manager\GameManager.h"
#include "BaseModel.h"
#include "Entity\AdvAreaData.h"
#include "Config.h"

class AdvView;

class AdvModel : public BaseModel
{


public:
	//����ð�ճ�����������
	cocos2d::Vector<AdvAreaData*> _advAreaInfos;
	//��ͼ
	AdvView* _view;

public:
	AdvModel();
	~AdvModel();

	virtual bool init();
	virtual bool init(AdvView* view);

	CREATE_WITH_VIEW(AdvModel, AdvView);

private:
	//��ȡ�浵������ð�ճ���ʵ��
	void getUserDataAndInitInfos();
	//��ȡ���棬��ȡ��ϸ��Ϣ
	void getDetailInfos();
};

#endif