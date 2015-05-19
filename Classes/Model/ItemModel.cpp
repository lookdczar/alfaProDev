#include "ItemModel.h"


ItemModel::ItemModel()
{
}


ItemModel::~ItemModel()
{
}

bool ItemModel::init()
{
	if (!BaseModel::init())
		return false;

	return true;
}

void ItemModel::getIteminfosBymap(const ValueMap& itemlist)
{
	for (auto item : itemlist)
	{
		Value ID = (Value)item.first;
		_itemInfos.pushBack(ItemData::create(ID));
	}
}

cocos2d::Vector<ItemData*> ItemModel::getDetailInfos()
{
	for (auto base : _itemInfos)
	{
		GET_MA_CACHE->bindCacheDataToEntity(RES_TYPE::itemInfo, base);
	}

	return _itemInfos;
}
