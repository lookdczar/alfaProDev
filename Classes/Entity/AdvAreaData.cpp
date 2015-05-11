#include "AdvAreaData.h"


AdvAreaData::AdvAreaData()
{
}


AdvAreaData::~AdvAreaData()
{
}

AdvAreaData::AdvAreaData(const ValueMap& mapData)
{
	initWithData(mapData);
}

bool AdvAreaData::init()
{
	return true;
}



//ʹ��Դ���ݳ�ʼ��Dataʵ��
bool AdvAreaData::initWithData(const ValueMap& mapData)
{
	bindingData(mapData);
	return true;
}

//������
bool AdvAreaData::bindingData(const ValueMap& mapData)
{
	areaId = mapData.at("areaId");
	//��������
	areaName = mapData.at("areaName");
	//����ͼƬ
	areaImg = mapData.at("areaImg");
	//�����ȼ�
	areaRank = mapData.at("areaRank");
	//��������  ��Ʒid������
	rewards = mapData.at("rewards").asValueMap();
	return true;
}