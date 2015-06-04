#include "FarmModel.h"
#include "Manager\GameManager.h"
#include "View\FarmView.h"

FarmModel::FarmModel()
{
}


FarmModel::~FarmModel()
{
}

bool FarmModel::init()
{
	if (!BaseModel::init())
		return false;

	return true;
}

bool FarmModel::init(FarmView* view)
{
	if (!BaseModel::init())
		return false;

	return true;
}

void FarmModel::getUserDataAndInitInfos()
{
	//获取已解锁的农场建筑ID
	Value&	vId = GET_MA_UDATA->getUserData(USER_DATA_TYPE::buildUnlocked);
	ValueVector &arrId = vId.asValueVector();
	//有多少id就创建多少场景实体
	for (auto id : arrId)
	{
		_farmBuildInfos.pushBack(FarmBuildData::create(id));
	}
}

void FarmModel::getDetailInfos()
{
	for (auto base : _farmBuildInfos)
	{
		GET_MA_CACHE->bindCacheDataToEntity(RES_TYPE::farmBuildInfo, base);
	}
}

void FarmModel::setbuildUnlock(int buildid)
{
	GET_MA_UDATA->setBuildUnlock(buildid);
}
