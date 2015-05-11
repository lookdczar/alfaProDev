
#ifndef _USER_DATA_H_
#define _USER_DATA_H_

#include "cocos2d.h"

USING_NS_CC;

//ĳ���û����ݣ�һ�����ݣ����ѽ���ð�ճ�����Ϊһ�����ݣ�UserData)
class UserData : public cocos2d::Ref
{
public:

	//�����û�����
	cocos2d::Value userData;

	//�ѽ���ð�ճ���
//	cocos2d::ValueVector advUnlocked;

public:
	UserData();
	~UserData();

	virtual bool init();
	virtual bool init(Value& value);

	CREATE_FUNC(UserData);
	//ʹ��map��ʼ��
	static UserData* create(Value& value);

};

#endif