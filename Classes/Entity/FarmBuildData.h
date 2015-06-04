#ifndef _FARM_BUILD_DATA_H_
#define	_FARM_BUILD_DATA_H_

#include "cocos2d.h"
#include "BaseDataEntity.h"

USING_NS_CC;

///ũ����������ʵ��
class FarmBuildData : public BaseDataEntity
{
public:
	//�������
	Value buildId;
	//��������
	Value buildName;
	//����ͼƬ
	Value buildImg;
	//����CD
	Value buildCD;
	//������Ʒ������Χ��ֵ
	Value collectNum;
	//������Ʒ�б�
	cocos2d::ValueMap collections;

public:
	FarmBuildData();
	~FarmBuildData();

	//ʹ��Դ���ݳ�ʼ��Dataʵ��
	FarmBuildData(const ValueMap& mapData);

	virtual bool init();
	//ʹ��id��ʼ������ʵ�� 
	CREATE_FUNC_ID(FarmBuildData);

	//ʹ��Դ���ݳ�ʼ��Dataʵ��
	virtual bool initWithData(const ValueMap& mapData);

	//������
	virtual bool bindingData(const ValueMap& mapData);
};

#endif
