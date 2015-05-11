#include "CacheManager.h"
#include "Manager\GameManager.h"
#include "CacheData.h"
#include "Entity\BaseDataEntity.h"
#include "Util\CommonHelper.h"

#include <cassert>

CacheManager::CacheManager()
{
	//读取数据文件路径plist
	ValueMap &pathMapAll = GET_MA_RES->readPlist(F_DATA_PATH);
	//初始化缓存数据集容器
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

//获取某个缓存数据
cocos2d::ValueMap CacheManager::getCacheData(RES_TYPE type)
{
	//从容器中拿出指定的缓存数据集
	CacheDataM* data = allData.at(resTypeStr[int(type)]);
	if(!data->hasRead) //是否已经读取
	{
		//读取数据plist
		data->cacheData = GET_MA_RES->readPlist(data->dataPath);
		//缓存图片
		GET_MA_RES->addBigImage(data->imgPath_B);
		for(auto imgS : data->imgPathArr_S)
		{
			GET_MA_RES->addSingleImage(imgS.asString());
		}
		data->hasRead = true;
	}
	return data->cacheData;
}
//根据数据编号获取缓存数据集中指定的数据
cocos2d::ValueMap CacheManager::getCacheData(RES_TYPE type, const Value& id)
{
	//读取指定数据集
	ValueMap &dataAll = getCacheData(type);

	//该数据是否存在，如果不存在触发断言
#ifdef DEV_STATUS
	char buffer[100];
	const char* strType = resTypeStr[int(type)].c_str();
	const std::string strId = id.asString();
	sprintf(buffer, "the CacheData with the id is null(type:%s),(id:%s)", strType, strId.c_str());
	bool isContain = CommonHelper::ValueMapContainsKey(dataAll, id.asString());
	CCASSERT(isContain, buffer);
#endif
	//从数据集中读取指定id的数据
	Value &data = dataAll[id.asString()];
	ValueMap &dataTarget = data.asValueMap();
	return dataTarget;
}

//将指定的缓存数据绑定到数据实体中
void CacheManager::bindCacheDataToEntity(RES_TYPE type, BaseDataEntity* entity)
{
	ValueMap &data = getCacheData(type, entity->dataId);
	entity->bindingData(data);
}

//绑定多个缓存数据到数据实体
void CacheManager::bindCacheDataToEntity(RES_TYPE type, Vector<BaseDataEntity*>& entities)
{
	if (entities.empty())
		return;
	for (auto entity : entities)
	{
		bindCacheDataToEntity(type, entity);
	}
}