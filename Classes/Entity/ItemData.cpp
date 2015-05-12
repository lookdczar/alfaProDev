#include "ItemData.h"


ItemData::ItemData()
{
}


ItemData::~ItemData()
{
}

ItemData::ItemData(const ValueMap& mapData)
{
	initWithData(mapData);
}

bool ItemData::init()
{
	return true;
}



//ʹ��Դ���ݳ�ʼ��Dataʵ��
bool ItemData::initWithData(const ValueMap& mapData)
{
	bindingData(mapData);
	return true;
}

//������
bool ItemData::bindingData(const ValueMap& mapData)
{
	//��Ʒ���
	itemId = mapData.at("itemId");
	//��Ʒ����
	itemName = mapData.at("itemName");
	//��ƷͼƬ
	itemImg = mapData.at("itemImg");
	//��Ʒ�ȼ�
	itemRank = mapData.at("itemRank");
	//��Ʒϡ�жȣ����ڼ�����ʡ������ʡ����������ϳɳɹ��ʵȣ�
	itemWorth = mapData.at("itemWorth");
	//��Ʒ���(���䣬�ݣ�ʯͷ��Ģ������������
	itemType = mapData.at("itemType");

	return true;
}