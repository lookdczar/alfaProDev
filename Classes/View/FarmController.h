#ifndef __FARM_CONTROLLER_H__
#define __FARM_CONTROLLER_H__

#include "cocos2d.h"
#include "BaseController.h"

class FarmModel;
class FarmView;
class FarmBuildData;
class ItemModel;
class ItemData;

class FarmController : public BaseController
{
public:
	FarmView* _view;
	FarmModel*	_model;

public:
	virtual bool init();

	void menuStartGameCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(FarmController);
	//通过建筑编号调物品缓存
	static cocos2d::Vector<ItemData*> getitemInfos(FarmBuildData* Fbuild);
};

#endif 