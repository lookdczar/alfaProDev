#include "FarmBuildData.h"


FarmBuildData::FarmBuildData()
{
}


FarmBuildData::~FarmBuildData()
{
}

FarmBuildData::FarmBuildData(const ValueMap& mapData)
{
	initWithData(mapData);
}

bool FarmBuildData::init()
{
	return true;
}



//ʹ��Դ���ݳ�ʼ��Dataʵ��
bool FarmBuildData::initWithData(const ValueMap& mapData)
{
	bindingData(mapData);
	return true;
}

//������
bool FarmBuildData::bindingData(const ValueMap& mapData)
{
	buildId = mapData.at("buildId");
	//��������
	buildName = mapData.at("buildName");
	//����ͼƬ
	buildImg = mapData.at("buildImg");
	//�����ɼ�CD
	buildCD = mapData.at("buildCD");
	//������Ʒ������Χ��ֵ
	collectNum = mapData.at("collectNum");
	//������Ʒ�б�
	collections = mapData.at("collections").asValueMap();
	return true;
}



