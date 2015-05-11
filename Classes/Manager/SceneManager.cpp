#include "SceneManager.h"


SceneManager::SceneManager()
{
	this->init();
}

SceneManager::~SceneManager()
{
}

bool SceneManager::init()
{
	if (!BaseManager::init())
		return false;
	return true;
}

void SceneManager::replaceScene(Scene* scene)
{
	Director::getInstance()->replaceScene(scene);
}

