
#ifndef _ITEM_DATA_H_
#define _ITEM_DATA_H_

#include "cocos2d.h"
#include "BaseDataEntity.h"

USING_NS_CC;

//��Ʒ���
typedef  enum struct itemType{
	//һ�������Ʒ
	common = 0,
	//������ֲ�Ĳ�
	plant,
	//����
	rock,
	//Ģ��
	mushroom,
	//enum������ʶ
	resTypeEnd
}  ITEM_TYPE;

///��Ʒ����ʵ��
class ItemData : public BaseDataEntity
{
public:
	//��Ʒ���
	Value itemId;
	//��Ʒ����
	Value itemName;
	//��ƷͼƬ
	Value itemImg;
	//��Ʒ�ȼ�
	Value itemRank;
	//��Ʒϡ�жȣ����ڼ�����ʡ������ʡ����������ϳɳɹ��ʵȣ�
	Value itemWorth;
	//��Ʒ���(���䣬�ݣ�ʯͷ��Ģ������������
	Value itemType;

public:
	ItemData();
	~ItemData();

	//ʹ��Դ���ݳ�ʼ��Dataʵ��
	ItemData(const ValueMap& mapData);

	virtual bool init();
	//ʹ��id��ʼ������ʵ�� 
	CREATE_FUNC_ID(ItemData);

	//ʹ��Դ���ݳ�ʼ��Dataʵ��
	virtual bool initWithData(const ValueMap& mapData);

	//������
	virtual bool bindingData(const ValueMap& mapData);
};

#endif