#ifndef _FARMUI_H_
#define _FARMUI_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class farmUI : public Node
{
public:

	//建筑框，加入建筑图片，按钮，时间条
	Sprite*	_buildBox;
	//建筑的菜单按钮
	Sprite*	_buttom1;
	Sprite*	_buttom2;
	//采集CD条
	LoadingBar* _CDbar;

public:
	farmUI();
	~farmUI();

	virtual	bool init();
	CREATE_FUNC(farmUI);

	//显示信息框
	void showinfoBox();
	//隐藏信息框
	void hideinfoBox();

};

#endif