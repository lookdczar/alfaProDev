
#ifndef _CACHE_DATA_H_
#define _CACHE_DATA_H_

#include "cocos2d.h"
#include "Config.h"

USING_NS_CC;

//ĳ������ݵ����ݼ���һ�����ݣ�������ð�ճ�����Ϣ��Ϊһ�����ݼ���CacheDataM)
class CacheDataM : public cocos2d::Ref
{
private:
	

public:
	//�������Ƿ��Ѷ�ȡ
	bool hasRead;
	//�������ݼ�
	cocos2d::ValueMap cacheData;

	//�����ݼ���Ҫ���ص������Դ��path
	//����СͼƬ��Դ
	ValueVector imgPathArr_S;
	//��ͼͼƬ��ԴΪ.plist
	std::string imgPath_B;
	//�����ļ� .plist
	std::string dataPath;
	//�������� ��studio�Ķ���

public:
	CacheDataM();
	~CacheDataM();

	virtual bool init();
	virtual bool init(const ValueMap& map);

	CREATE_FUNC(CacheDataM);
	//ʹ��map��ʼ����ֱ�Ӱ�path
	static CacheDataM* create(const ValueMap& map);

	//����Դpath
	void bindResPath(const ValueMap& map);
};

#endif