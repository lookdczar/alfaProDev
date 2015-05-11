
#ifndef _ADV_AREA_DATA_H_
#define _ADV_AREA_DATA_H_

#include "cocos2d.h"
#include "BaseDataEntity.h"

USING_NS_CC;

///ð�ճ�������ʵ��
class AdvAreaData : public BaseDataEntity
{
public:
	//�������
	Value areaId;
	//��������
	Value areaName;
	//����ͼƬ
	Value areaImg;
	//�����ȼ�
	Value areaRank;
	//��������  ��Ʒid������
	cocos2d::ValueMap rewards;

public:
	AdvAreaData();
	~AdvAreaData();

	//ʹ��Դ���ݳ�ʼ��Dataʵ��
	AdvAreaData(const ValueMap& mapData);

	virtual bool init();
	//ʹ��id��ʼ������ʵ�� 
	CREATE_FUNC_ID(AdvAreaData);

	//ʹ��Դ���ݳ�ʼ��Dataʵ��
	virtual bool initWithData(const ValueMap& mapData);

	//������
	virtual bool bindingData(const ValueMap& mapData);
};

#endif