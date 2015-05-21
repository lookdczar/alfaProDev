#ifndef _INFOBOX_H_
#define _INFOBOX_H_

#include "cocos2d.h"
#include "Config.h"
USING_NS_CC;

class FarmBuildData;

class infoBox : public Sprite
{
private:
	static infoBox* infobox;

public:
	//信息框关闭按钮
	Sprite*	_closeButtom;
	//关闭菜单
	Menu* _menu;
	//信息框
	Sprite*	_infoBox;
public:
	infoBox();
	~infoBox();

	static infoBox* getInstance();
	static void destroyInstance();

	virtual bool init();

	//隐藏信息框
	void hideInfoBox(cocos2d::Object* pSender);
	//重置信息框
	void resetInfoBox();
};

#endif