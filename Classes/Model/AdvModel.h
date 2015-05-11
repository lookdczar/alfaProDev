
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
	//所有冒险场景数据数组
	cocos2d::Vector<AdvAreaData*> _advAreaInfos;
	//视图
	AdvView* _view;

public:
	AdvModel();
	~AdvModel();

	virtual bool init();
	virtual bool init(AdvView* view);

	CREATE_WITH_VIEW(AdvModel, AdvView);

private:
	//读取存档，创建冒险场景实体
	void getUserDataAndInitInfos();
	//读取缓存，获取详细信息
	void getDetailInfos();
};

#endif