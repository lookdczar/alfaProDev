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

	//ͨ��map��ȡ��Ʒ��ϸ��Ϣ,map��keyΪ��Ʒ���
	void getIteminfosBymap(const ValueMap& itemlist);
	//��ȡ��ϸ��Ϣ
	cocos2d::Vector<ItemData*> getDetailInfos();
};

#endif