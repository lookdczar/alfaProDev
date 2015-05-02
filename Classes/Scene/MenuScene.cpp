#include "MenuScene.h"
#include "Manager\GameManager.h"

USING_NS_CC;

bool MenuScene::init()
{ 
	if (!BaseScene::init())
		return false;

	//≥ı ºªØGameManager
	GameManager::getInstance();

	//º”‘ÿcontroller
	menuController = MenuController::create();
	addChild(menuController);
    
    return true;
}



