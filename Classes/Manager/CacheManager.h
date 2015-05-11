
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
	 //���л������ݼ���������һ�����ݣ�������ð�ճ�����Ϣ��Ϊһ�����ݼ���CacheDataM)
	cocos2d::Map<std::string,CacheDataM*> allData;
	
public:
	CacheManager();
	~CacheManager();

	virtual bool init();

	//��ȡĳ���������ݼ�
	cocos2d::ValueMap getCacheData(RES_TYPE type);
	//�������ݱ�Ż�ȡ�������ݼ���ָ��������
	cocos2d::ValueMap getCacheData(RES_TYPE type,const Value& id);
	//��ָ���Ļ������ݰ󶨵�����ʵ����
	void bindCacheDataToEntity(RES_TYPE type,BaseDataEntity* entity );
	//�󶨶���������ݵ�����ʵ��
	void bindCacheDataToEntity(RES_TYPE type, Vector<BaseDataEntity*>& entity);
};

#endif