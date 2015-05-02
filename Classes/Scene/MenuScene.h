#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"
#include "BaseScene.h"
#include "View\MenuController.h"

class MenuScene : public BaseScene
{
public:
	MenuController* menuController;

public:
    virtual bool init();    

	CREATE_FUNC(MenuScene);
};

#endif 
