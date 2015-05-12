#ifndef _CONFIG_H_
#define _CONFIG_H_

//�Ƿ��ǿ���״̬
#define DEV_STATUS

/******************����#include************************/
//#include "Manager\GameManager.h"

/***********��ȡ��Դ������ ��GET_MA��ͷ ************/
#define GET_MA_SCENE GameManager::getInstance()->sceneManager
#define GET_MA_RES GameManager::getInstance()->resManager
#define GET_MA_CACHE GameManager::getInstance()->cacheManager
#define GET_MA_UDATA GameManager::getInstance()->userDataManager



/*****************�������Ͷ���***********************/
/** ����������Դ���� */
typedef  enum struct resType{
	//ð�ճ�����Ϣ
	advAreaInfo = 0,
	itemInfo,
	//enum������ʶ
	resTypeEnd
}  RES_TYPE;

static std::string resTypeStr[int(RES_TYPE::resTypeEnd)] = {"advAreaInfo,itemInfo"};

/** �û�������Դ���� */
typedef  enum  struct userDataType{
	//�ѽ���ð�ճ���
	advUnlocked = 0,
	//enum������ʶ
	userDataEnd
}  USER_DATA_TYPE;

static std::string userDataTypeStr[int(USER_DATA_TYPE::userDataEnd)] = { "advUnlocked" };


/****************�����ļ���������F_��ͷ***************/
//�û��浵�ļ�
#define F_USER_DATA "UserData.plist"
//��¼������Ϸ���ݼ���Դ��Ҫ��ȡ���ļ���·�����������������ȡ
#define F_DATA_PATH "GameDataPath.plist"


/******�������ݶ�Ӧ�ļ�����gameDataPath.plist�еļ���Ӧ**********/
#define P_IMG_S			"imgSingleArr"
#define P_IMG_B			"imgBigPlist"
#define P_DATA_PLIST	"dataPlist"

/******************************���˺�*********************************/
#define VISIBLE_SIZE Size visibleSize = Director::getInstance()->getVisibleSize(); \
Vec2 origin = Director::getInstance()->getVisibleOrigin(); \

#endif