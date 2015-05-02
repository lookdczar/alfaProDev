
#ifndef _SCENE_MANAGER_H_
#define _SCENE_MANAGER_H_

#include "cocos2d.h"
#include "BaseManager.h"

USING_NS_CC;

class SceneManager : public BaseManager
{
public:
	SceneManager();
	~SceneManager();

	//ÇÐ»»³¡¾°
	void replaceScene(Scene* scene);

	virtual bool init();
};

#endif