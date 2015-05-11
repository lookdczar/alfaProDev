
#ifndef _USER_DATA_MANAGER_H_
#define _USER_DATA_MANAGER_H_

#include "cocos2d.h"
#include "BaseManager.h"
#include "UserData.h"

class UserDataManager : public BaseManager
{

private:
	//�����û����ݵ�������һ�����ݣ����ѽ���ð�ճ�����Ϊһ�����ݣ�UserData)
	cocos2d::Map<std::string, UserData*> allData;

public:
	UserDataManager();
	~UserDataManager();

	virtual bool init();

	//��ȡ�ѽ���ð�ճ������
	UserData* getAdvUnlockedInfo();

	//��ȡĳ���û�����
	cocos2d::Value getUserData(USER_DATA_TYPE type);

	//���浱ǰ�û�����
	bool saveAllUserData();
};

#endif