#include "UserDataManager.h"
#include "Manager\GameManager.h"
#include "Util\FileHelper.h"

UserDataManager::UserDataManager()
{
	//userData = UserData::create();
	//userData->retain();

	//初始化用户数据集容器
	//读取用户存档plist
	ValueMap &userDataSource = GET_MA_RES->readPlist(F_USER_DATA);
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


//获取某个缓存数据
cocos2d::Value UserDataManager::getUserData(USER_DATA_TYPE type)
{
	UserData* data = allData.at(userDataTypeStr[int(type)]);
	return data->userData;
}

//保存当前用户数据
bool UserDataManager::saveAllUserData()
{
	ValueMap map;
	for (auto data : allData)
	{
		map[data.first] = data.second->userData;
	}
	return FileHelper::plistWriteFile(map, F_USER_DATA);
}

//获取已解锁冒险场景编号
Value& UserDataManager::getAdvUnlockedInfo()
{
	return allData.at(userDataTypeStr[int(USER_DATA_TYPE::advUnlocked)])->userData;
}

//获取用户所有的物品
ValueMap& UserDataManager::getUserItems()
{
	Value &itemsValue = allData.at(userDataTypeStr[int(USER_DATA_TYPE::userItems)])->userData;
	return itemsValue.asValueMap();
}

//获取指定用户所有的指定id的物品数量，没有为0
Value& UserDataManager::getUserItemCount(const std::string& itemId)
{
	Value &itemsValue = allData.at(userDataTypeStr[int(USER_DATA_TYPE::userItems)])->userData;
	ValueMap &itemsMap = itemsValue.asValueMap();
	return itemsMap.at(itemId);
}

//设置指定用户所有的指定id的物品数量,可为负数
void UserDataManager::setUserItemCount(const std::string& itemId, int count)
{
	Value &itemsValue = allData.at(userDataTypeStr[int(USER_DATA_TYPE::userItems)])->userData;
	ValueMap &itemsMap = itemsValue.asValueMap();
	itemsMap[itemId] = Value(count);
}
	
