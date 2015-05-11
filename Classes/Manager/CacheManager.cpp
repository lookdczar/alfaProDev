#include "CacheManager.h"
#include "Manager\GameManager.h"
#include "CacheData.h"
#include "Entity\BaseDataEntity.h"
#include "Util\CommonHelper.h"

#include <cassert>

CacheManager::CacheManager()
{
	//��ȡ�����ļ�·��plist
	ValueMap &pathMapAll = GET_MA_RES->readPlist(F_DATA_PATH);
	//��ʼ���������ݼ�����
	//Value &pathMap = Value();
	for(int i=0;i<int(RES_TYPE::resTypeEnd);i++)
	{
		ValueMap &pathMap = pathMapAll.at(resTypeStr[i]).asValueMap();
		allData.insert(resTypeStr[i],CacheDataM::create(pathMap));
	}
}


CacheManager::~CacheManager()
{
}

bool CacheManager::init()
{
	return true;
}

//��ȡĳ����������
cocos2d::ValueMap CacheManager::getCacheData(RES_TYPE type)
{
	//���������ó�ָ���Ļ������ݼ�
	CacheDataM* data = allData.at(resTypeStr[int(type)]);
	if(!data->hasRead) //�Ƿ��Ѿ���ȡ
	{
		//��ȡ����plist
		data->cacheData = GET_MA_RES->readPlist(data->dataPath);
		//����ͼƬ
		GET_MA_RES->addBigImage(data->imgPath_B);
		for(auto imgS : data->imgPathArr_S)
		{
			GET_MA_RES->addSingleImage(imgS.asString());
		}
		data->hasRead = true;
	}
	return data->cacheData;
}
//�������ݱ�Ż�ȡ�������ݼ���ָ��������
cocos2d::ValueMap CacheManager::getCacheData(RES_TYPE type, const Value& id)
{
	//��ȡָ�����ݼ�
	ValueMap &dataAll = getCacheData(type);

	//�������Ƿ���ڣ���������ڴ�������
#ifdef DEV_STATUS
	char buffer[100];
	const char* strType = resTypeStr[int(type)].c_str();
	const std::string strId = id.asString();
	sprintf(buffer, "the CacheData with the id is null(type:%s),(id:%s)", strType, strId.c_str());
	bool isContain = CommonHelper::ValueMapContainsKey(dataAll, id.asString());
	CCASSERT(isContain, buffer);
#endif
	//�����ݼ��ж�ȡָ��id������
	Value &data = dataAll[id.asString()];
	ValueMap &dataTarget = data.asValueMap();
	return dataTarget;
}

//��ָ���Ļ������ݰ󶨵�����ʵ����
void CacheManager::bindCacheDataToEntity(RES_TYPE type, BaseDataEntity* entity)
{
	ValueMap &data = getCacheData(type, entity->dataId);
	entity->bindingData(data);
}

//�󶨶���������ݵ�����ʵ��
void CacheManager::bindCacheDataToEntity(RES_TYPE type, Vector<BaseDataEntity*>& entities)
{
	if (entities.empty())
		return;
	for (auto entity : entities)
	{
		bindCacheDataToEntity(type, entity);
	}
}