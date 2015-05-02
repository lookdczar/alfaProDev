#include "GameManager.h"

USING_NS_CC;

GameManager* GameManager::gameManager = nullptr;

GameManager::GameManager()
{
}

GameManager* GameManager::getInstance()
{
	if (gameManager == nullptr)
	{
		gameManager = new GameManager();
		gameManager->init();
	}
	return gameManager;
}

GameManager::~GameManager()
{
}


void GameManager::destroyInstance()
{
	CC_SAFE_DELETE(gameManager);
}

void GameManager::init()
{
	sceneManager = new SceneManager();

	return ;
}
