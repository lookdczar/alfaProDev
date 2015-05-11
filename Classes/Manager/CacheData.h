
#ifndef _CACHE_DATA_H_
#define _CACHE_DATA_H_

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;

//某项缓存数据的数据集，一种数据（如所有冒险场景信息）为一个数据集（CacheDataM)
class CacheDataM : public cocos2d::Ref
{
private:
	

public:
	//该数据是否已读取
	bool hasRead;
	//具体数据集
	cocos2d::ValueMap cacheData;

	//该数据集需要加载的相关资源的path
	//单个小图片资源
	ValueVector imgPathArr_S;
	//大图图片资源为.plist
	std::string imgPath_B;
	//数据文件 .plist
	std::string dataPath;
	//其他待定 如studio的动画

public:
	CacheDataM();
	~CacheDataM();

	virtual bool init();
	virtual bool init(const ValueMap& map);

	CREATE_FUNC(CacheDataM);
	//使用map初始化，直接绑定path
	static CacheDataM* create(const ValueMap& map);

	//绑定资源path
	void bindResPath(const ValueMap& map);
};

#endif