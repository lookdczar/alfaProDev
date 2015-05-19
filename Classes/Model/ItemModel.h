#ifndef _ITEM_MODEL_H_
#define _ITEM_MODEL_H_

#include "cocos2d.h"
#include "Manager\GameManager.h"
#include "BaseModel.h"
#include "Entity/ItemData.h"
#include "Config.h"

class ItemModel : public BaseModel
{
public:
	cocos2d::Vector<ItemData*> _itemInfos;
public:
	ItemModel();
	~ItemModel();

	virtual bool init();

	CREATE_FUNC(ItemModel);

	//通过map获取物品详细信息,map的key为物品编号
	void getIteminfosBymap(const ValueMap& itemlist);
	//获取详细信息
	cocos2d::Vector<ItemData*> getDetailInfos();
};

#endif