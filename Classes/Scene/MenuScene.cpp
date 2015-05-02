#include "MenuScene.h"
#include "Manager\GameManager.h"

USING_NS_CC;

bool MenuScene::init()
{ 
	if (!BaseScene::init())
		return false;

	//��ʼ��GameManager
	GameManager::getInstance();

	//����controller
	menuController = MenuController::create();
	addChild(menuController);
    
    return true;
}



