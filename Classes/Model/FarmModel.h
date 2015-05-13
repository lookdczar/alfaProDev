#ifndef _FARM_MODEL_H_
#define _FARM_MODEL_H_

#include "cocos2d.h"
#include "Manager\GameManager.h"
#include "BaseModel.h"
#include "Entity/FarmBuildData.h"
#include "Config.h"

class FarmView;

class FarmModel : public BaseModel
{
public:
	//����ð�ճ�����������
	cocos2d::Vector<FarmBuildData*> _farmBuildInfos;
	//��ͼ
	FarmView* _view;

public:
	FarmModel();
	~FarmModel();

	virtual bool init();
	virtual bool init(FarmView* view);

	CREATE_WITH_VIEW(FarmModel, FarmView);

	//��ȡ�浵������ð�ճ���ʵ��
	void getUserDataAndInitInfos();
	//��ȡ���棬��ȡ��ϸ��Ϣ
	void getDetailInfos();
};

#endif
