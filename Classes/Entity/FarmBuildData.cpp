#include "FarmBuildData.h"


FarmBuildData::FarmBuildData()
{
}


FarmBuildData::~FarmBuildData()
{
}

FarmBuildData::FarmBuildData(const ValueMap& mapData)
{
	initWithData(mapData);
}

bool FarmBuildData::init()
{
	return true;
}



//使用源数据初始化Data实体
bool FarmBuildData::initWithData(const ValueMap& mapData)
{
	bindingData(mapData);
	return true;
}

//绑定数据
bool FarmBuildData::bindingData(const ValueMap& mapData)
{
	buildId = mapData.at("buildId");
	//场景名称
	buildName = mapData.at("buildName");
	//场景图片
	buildImg = mapData.at("buildImg");
	//建筑采集CD
	buildCD = mapData.at("buildCD");
	//掉落物品数量范围均值
	collectNum = mapData.at("collectNum");
	//掉落物品列表
	collections = mapData.at("collections").asValueMap();
	return true;
}



