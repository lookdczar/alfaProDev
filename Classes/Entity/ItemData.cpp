#include "ItemData.h"


ItemData::ItemData()
{
}


ItemData::~ItemData()
{
}

ItemData::ItemData(const ValueMap& mapData)
{
	initWithData(mapData);
}

bool ItemData::init()
{
	return true;
}



//使用源数据初始化Data实体
bool ItemData::initWithData(const ValueMap& mapData)
{
	bindingData(mapData);
	return true;
}

//绑定数据
bool ItemData::bindingData(const ValueMap& mapData)
{
	//物品编号
	itemId = mapData.at("itemId");
	//物品名称
	itemName = mapData.at("itemName");
	//物品图片
	itemImg = mapData.at("itemImg");
	//物品等级
	itemRank = mapData.at("itemRank");
	//物品稀有度（用于计算掉率、产出率、产出数、合成成功率等）
	itemWorth = mapData.at("itemWorth");
	//物品类别(掉落，草，石头，蘑菇。。。。）
	itemType = mapData.at("itemType");

	return true;
}