#include "GameScene.h"
#include "Manager\GameManager.h"
#include "View\ShopController.h"
#include "View\CreateController.h"
#include "View\AdvController.h"

USING_NS_CC;

bool GameScene::init()
{ 
	if (!BaseScene::init())
		return false;

	//│§╩╝╗»UIManager
	gameUI = UIManager::create(ShopController::create(),CreateController::create(),AdvController::create());
    
	addChild(gameUI);

    return true;
}



