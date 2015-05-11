
#ifndef _CACHE_MANAGER_H_
#define _CACHE_MANAGER_H_

#include "cocos2d.h"
#include "BaseManager.h"

USING_NS_CC;

class CacheDataM;
class BaseDataEntity;

class CacheManager : public BaseManager
{
private:
	 //所有缓存数据集的容器，一种数据（如所有冒险场景信息）为一个数据集（CacheDataM)
	cocos2d::Map<std::string,CacheDataM*> allData;
	
public:
	CacheManager();
	~CacheManager();

	virtual bool init();

	//获取某个缓存数据集
	cocos2d::ValueMap getCacheData(RES_TYPE type);
	//根据数据编号获取缓存数据集中指定的数据
	cocos2d::ValueMap getCacheData(RES_TYPE type,const Value& id);
	//将指定的缓存数据绑定到数据实体中
	void bindCacheDataToEntity(RES_TYPE type,BaseDataEntity* entity );
	//绑定多个缓存数据到数据实体
	void bindCacheDataToEntity(RES_TYPE type, Vector<BaseDataEntity*>& entity);
};

#endif