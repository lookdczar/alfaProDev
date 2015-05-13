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

//��ȡ�浵������ð�ճ���ʵ��
void AdvModel::getUserDataAndInitInfos()
{
	//��ȡ�Ѿ������ĳ���id
	Value& vId = GET_MA_UDATA->getUserData(USER_DATA_TYPE::advUnlocked);
	ValueVector &arrId = vId.asValueVector();
	//�ж���id�ʹ������ٳ���ʵ��
	 for (auto id : arrId)
	 {
		 _advAreaInfos.pushBack(AdvAreaData::create(id));
	 }

}

//��ȡ���棬��ȡ��ϸ��Ϣ
void AdvModel::getDetailInfos()
{
	for (auto base : _advAreaInfos)
	{
		GET_MA_CACHE->bindCacheDataToEntity(RES_TYPE::advAreaInfo,base);
	}
}