
#ifndef _ITEM_DATA_H_
#define _ITEM_DATA_H_

#include "cocos2d.h"
#include "BaseDataEntity.h"

USING_NS_CC;

///物品数据实体
class ItemData : public BaseDataEntity
{
public:
	//物品编号
	Value itemId;
	//物品名称
	Value itemName;
	//物品图片
	Value itemImg;
	//物品等级
	Value itemRank;
	//物品稀有度（用于计算掉率、产出率、产出数、合成成功率等）
	Value itemWorth;

public:
	ItemData();
	~ItemData();

	//使用源数据初始化Data实体
	ItemData(const ValueMap& mapData);

	virtual bool init();
	//使用id初始化数据实体 
	CREATE_FUNC_ID(ItemData);

	//使用源数据初始化Data实体
	virtual bool initWithData(const ValueMap& mapData);

	//绑定数据
	virtual bool bindingData(const ValueMap& mapData);
};

#endif