#include "UserDataManager.h"
#include "Manager\GameManager.h"
#include "Util\FileHelper.h"

UserDataManager::UserDataManager()
{
	//userData = UserData::create();
	//userData->retain();

	//��ʼ���û����ݼ�����
	//��ȡ�û��浵plist
	ValueMap &userDataSource = GET_MA_RES->readPlist(F_USER_DATA/*"../Resources/UserData.plist"*/);
	for (int i = 0; i < int(USER_DATA_TYPE::userDataEnd); i++)
	{
		UserData * data = UserData::create(userDataSource[userDataTypeStr[i]]);
		allData.insert(userDataTypeStr[i], data);
	}
}


UserDataManager::~UserDataManager()
{
//	CC_SAFE_RELEASE(userData);
}

bool UserDataManager::init()
{

		//allData.at(userDataTypeStr[i])->userData = userDataSource[userDataTypeStr[i]];
	return true;
}


//��ȡĳ����������
cocos2d::Value UserDataManager::getUserData(USER_DATA_TYPE type)
{
	UserData* data = allData.at(userDataTypeStr[int(type)]);
	return data->userData;
}

//���浱ǰ�û�����
bool UserDataManager::saveAllUserData()
{
	ValueMap map;
	for (auto data : allData)
	{
		map[data.first] = data.second->userData;
	}
	return FileHelper::plistWriteFile(map, /*F_USER_DATA*//*"Debug.win32/UserData.plist"*/"../Resources/UserData.plist");
}

//��ȡ�ѽ���ð�ճ������
Value& UserDataManager::getAdvUnlockedInfo()
{
	return allData.at(userDataTypeStr[int(USER_DATA_TYPE::advUnlocked)])->userData;
}

//��ȡ�û����е���Ʒ
ValueMap& UserDataManager::getUserItems()
{
	Value &itemsValue = allData.at(userDataTypeStr[int(USER_DATA_TYPE::userItems)])->userData;
	return itemsValue.asValueMap();
}

//��ȡָ���û����е�ָ��id����Ʒ������û��Ϊ0
Value& UserDataManager::getUserItemCount(const std::string& itemId)
{
	Value &itemsValue = allData.at(userDataTypeStr[int(USER_DATA_TYPE::userItems)])->userData;
	ValueMap &itemsMap = itemsValue.asValueMap();
	return itemsMap.at(itemId);
}

//����ָ���û����е�ָ��id����Ʒ����,��Ϊ����
void UserDataManager::setUserItemCount(const std::string& itemId, int count)
{
	Value &itemsValue = allData.at(userDataTypeStr[int(USER_DATA_TYPE::userItems)])->userData;
	ValueMap &itemsMap = itemsValue.asValueMap();
	itemsMap[itemId] = Value(count);
}

void UserDataManager::setBuildUnlock(int buildid)
{
	Value& buildUnlock = allData.at(userDataTypeStr[int(USER_DATA_TYPE::buildUnlocked)])->userData;
	ValueVector& arrID = buildUnlock.asValueVector();
	int i = 0;
	for (auto id : arrID)
	{
		if (buildid == id.asInt())
		{
			char str[10];
			if (buildid + 6 < 10)
			{
				sprintf(str, "00%d", (buildid + 6));
			}
			else
			{
				sprintf(str, "0%d", (buildid + 6));
			}
			arrID[i] = std::string(str);
			saveAllUserData();
		}
		i++;
	}
}


