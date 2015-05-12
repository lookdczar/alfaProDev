#ifndef _CONFIG_H_
#define _CONFIG_H_

//是否是开发状态
#define DEV_STATUS

/******************常用#include************************/
//#include "Manager\GameManager.h"

/***********获取资源管理器 以GET_MA开头 ************/
#define GET_MA_SCENE GameManager::getInstance()->sceneManager
#define GET_MA_RES GameManager::getInstance()->resManager
#define GET_MA_CACHE GameManager::getInstance()->cacheManager
#define GET_MA_UDATA GameManager::getInstance()->userDataManager



/*****************数据类型定义***********************/
/** 缓存数据资源类型 */
typedef  enum struct resType{
	//冒险场景信息
	advAreaInfo = 0,
	itemInfo,
	//enum结束标识
	resTypeEnd
}  RES_TYPE;

static std::string resTypeStr[int(RES_TYPE::resTypeEnd)] = {"advAreaInfo,itemInfo"};

/** 用户数据资源类型 */
typedef  enum  struct userDataType{
	//已解锁冒险场景
	advUnlocked = 0,
	//enum结束标识
	userDataEnd
}  USER_DATA_TYPE;

static std::string userDataTypeStr[int(USER_DATA_TYPE::userDataEnd)] = { "advUnlocked" };


/****************所有文件名定义以F_开头***************/
//用户存档文件
#define F_USER_DATA "UserData.plist"
//记录各个游戏数据及资源需要读取的文件的路径，供缓存管理器读取
#define F_DATA_PATH "GameDataPath.plist"


/******缓存数据对应文件，与gameDataPath.plist中的键对应**********/
#define P_IMG_S			"imgSingleArr"
#define P_IMG_B			"imgBigPlist"
#define P_DATA_PLIST	"dataPlist"

/******************************懒人宏*********************************/
#define VISIBLE_SIZE Size visibleSize = Director::getInstance()->getVisibleSize(); \
Vec2 origin = Director::getInstance()->getVisibleOrigin(); \

#endif