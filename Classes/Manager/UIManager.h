
#ifndef _UI_MANAGER_H_
#define _UI_MANAGER_H_

#include "cocos2d.h"
#include "BaseManager.h"
#include "ui\UIScale9Sprite.h"

USING_NS_CC;

class UIManager : public Layer
{
public:
	Size tabBarSize;

private:
	LayerMultiplex* _layers;
	Menu* _tabBar;
	ui::Scale9Sprite* _tabBarBg;
	Vector<Layer*> _arrayOfLayers;

public:
	UIManager();
	~UIManager();

	virtual bool init();
	virtual bool initWithLayers(Layer *layer, va_list params);

	CREATE_FUNC(UIManager);
	static UIManager * create(Layer* layer, ...);

private:
	void tapBarPressed(Ref* pSender);
	void onEnter();

};

#endif