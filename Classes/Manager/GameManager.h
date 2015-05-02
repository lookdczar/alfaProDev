
#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "cocos2d.h"
#include "SceneManager.h"

class GameManager : public cocos2d::Ref
{
public:
	SceneManager* sceneManager;

private:
	static GameManager* gameManager;

public:
	static GameManager* getInstance();
	static void destroyInstance();


private:
	GameManager();
	~GameManager();
	void init();
};

#endif