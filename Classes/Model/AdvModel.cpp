#include "AdvModel.h"
#include "Manager\GameManager.h"
#include "View\AdvView.h"

AdvModel::AdvModel()
{
}


AdvModel::~AdvModel()
{
}

bool AdvModel::init()
{
	if (!BaseModel::init())
		return false;

	return true;
}

bool AdvModel::init(AdvView* view)
{
	if (!BaseModel::init())
		return false;

	return true;
}

//读取存档，创建冒险场景实体
void AdvModel::getUserDataAndInitInfos()
{
	//获取已经解锁的场景id
	Value& vId = GET_MA_UDATA->getUserData(USER_DATA_TYPE::advUnlocked);
	ValueVector &arrId = vId.asValueVector();
	//有多少id就创建多少场景实体
	 for (auto id : arrId)
	 {
		 _advAreaInfos.pushBack(AdvAreaData::create(id));
	 }

}

//读取缓存，获取详细信息
void AdvModel::getDetailInfos()
{
	for (auto base : _advAreaInfos)
	{
		GET_MA_CACHE->bindCacheDataToEntity(RES_TYPE::advAreaInfo,base);
	}
}