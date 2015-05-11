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
	CC_SAFE_RELEASE(sceneManager);
	CC_SAFE_RELEASE(resManager);
	CC_SAFE_RELEASE(cacheManager);
	CC_SAFE_RELEASE(userDataManager);
}


void GameManager::destroyInstance()
{
	CC_SAFE_DELETE(gameManager);
}

void GameManager::init()
{
	sceneManager = new SceneManager();
	resManager = new ResourceManager();
	cacheManager = new CacheManager();
	userDataManager = new UserDataManager();

	return ;
}
