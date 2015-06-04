#ifndef _FARMUI_H_
#define _FARMUI_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <vector>

USING_NS_CC;
using namespace ui;

class FarmBuildData;
class infoBox;
class FarmController;

class FarmUI : public Node
{
public:

	//建筑框，加入建筑图片，按钮，时间条
	Sprite*	_buildBox;
	//建筑的菜单按钮
	Sprite*	_buttom1;
	Sprite*	_buttom2;
	Sprite* _buttom3;
	//采集CD条
	LoadingBar* _CDbar;
	//用于CD计时
	float _CDcount;

public:
	//用于储存创建的FarmUI
	static cocos2d::Vector<FarmUI*> _farmUIs;
	//储存各建筑的CD
	static std::vector<int> _buildCDs;

public:
	FarmUI();
	~FarmUI();

	virtual	bool init();
	CREATE_FUNC(FarmUI);

	//创建各个按钮的回调函数
	void InitBuildBox(FarmBuildData* Fbuild, FarmController* _Delegate);
	//按下按钮显示信息框
	void showInfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmController* _Delegate);
	//建筑采集函数
	void fBuildCollect(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmUI* FUI, FarmController* _Delegate);
	//CD条更新
	void CDupdate(float delta);
	//升级建筑函数
	void BuilldUpdate(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmController* _Delegate);
};




class GainBox : public Sprite
{
private:
	static GainBox* gainBox;

public:
	//信息框关闭按钮
	Sprite*	_closeButtom;
	//关闭菜单
	Menu* _menu;
	//信息框
	Sprite*	_GainBox;

public:
	GainBox();
	~GainBox();

	static GainBox* getInstance();
	static void destroyInstance();

	virtual bool init();

	//隐藏信息框
	void hideGainBoxCallback(cocos2d::Object* pSender);
	void hideGainBox();
	//重置信息框
	void resetGainBox();
};

#endif