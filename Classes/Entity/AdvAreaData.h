
#ifndef _ADV_AREA_DATA_H_
#define _ADV_AREA_DATA_H_

#include "cocos2d.h"
#include "BaseDataEntity.h"

USING_NS_CC;

///冒险场景数据实体
class AdvAreaData : public BaseDataEntity
{
public:
	//场景编号
	Value areaId;
	//场景名称
	Value areaName;
	//场景图片
	Value areaImg;
	//场景等级
	Value areaRank;
	//场景掉落  物品id，掉率
	cocos2d::ValueMap rewards;

public:
	AdvAreaData();
	~AdvAreaData();

	//使用源数据初始化Data实体
	AdvAreaData(const ValueMap& mapData);

	virtual bool init();
	//使用id初始化数据实体 
	CREATE_FUNC_ID(AdvAreaData);

	//使用源数据初始化Data实体
	virtual bool initWithData(const ValueMap& mapData);

	//绑定数据
	virtual bool bindingData(const ValueMap& mapData);
};

#endif