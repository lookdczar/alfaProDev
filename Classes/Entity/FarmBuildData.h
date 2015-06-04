#ifndef _FARM_BUILD_DATA_H_
#define	_FARM_BUILD_DATA_H_

#include "cocos2d.h"
#include "BaseDataEntity.h"

USING_NS_CC;

///农场建筑数据实体
class FarmBuildData : public BaseDataEntity
{
public:
	//场景编号
	Value buildId;
	//场景名称
	Value buildName;
	//场景图片
	Value buildImg;
	//场景CD
	Value buildCD;
	//掉落物品数量范围均值
	Value collectNum;
	//掉落物品列表
	cocos2d::ValueMap collections;

public:
	FarmBuildData();
	~FarmBuildData();

	//使用源数据初始化Data实体
	FarmBuildData(const ValueMap& mapData);

	virtual bool init();
	//使用id初始化数据实体 
	CREATE_FUNC_ID(FarmBuildData);

	//使用源数据初始化Data实体
	virtual bool initWithData(const ValueMap& mapData);

	//绑定数据
	virtual bool bindingData(const ValueMap& mapData);
};

#endif
