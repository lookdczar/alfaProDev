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
	//所有冒险场景数据数组
	cocos2d::Vector<FarmBuildData*> _farmBuildInfos;
	//视图
	FarmView* _view;

public:
	FarmModel();
	~FarmModel();

	virtual bool init();
	virtual bool init(FarmView* view);

	CREATE_WITH_VIEW(FarmModel, FarmView);

	//读取存档，创建冒险场景实体
	void getUserDataAndInitInfos();
	//读取缓存，获取详细信息
	void getDetailInfos();
};

#endif
