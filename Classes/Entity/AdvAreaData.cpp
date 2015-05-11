#include "AdvAreaData.h"


AdvAreaData::AdvAreaData()
{
}


AdvAreaData::~AdvAreaData()
{
}

AdvAreaData::AdvAreaData(const ValueMap& mapData)
{
	initWithData(mapData);
}

bool AdvAreaData::init()
{
	return true;
}



//使用源数据初始化Data实体
bool AdvAreaData::initWithData(const ValueMap& mapData)
{
	bindingData(mapData);
	return true;
}

//绑定数据
bool AdvAreaData::bindingData(const ValueMap& mapData)
{
	areaId = mapData.at("areaId");
	//场景名称
	areaName = mapData.at("areaName");
	//场景图片
	areaImg = mapData.at("areaImg");
	//场景等级
	areaRank = mapData.at("areaRank");
	//场景掉落  物品id，掉率
	rewards = mapData.at("rewards").asValueMap();
	return true;
}