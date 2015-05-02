#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "BaseScene.h"
#include "Manager\UIManager.h"

class GameScene : public BaseScene
{
public:

private:
	UIManager* gameUI;

public:
    virtual bool init();    

	CREATE_FUNC(GameScene);
};

#endif 
