#include "GameScene.h"
#include "Manager\GameManager.h"
#include "View\ShopController.h"
#include "View\CreateController.h"

USING_NS_CC;

bool GameScene::init()
{ 
	if (!BaseScene::init())
		return false;

	//≥ı ºªØUIManager
	gameUI = UIManager::create(ShopController::create(),CreateController::create());
    
	addChild(gameUI);

    return true;
}



