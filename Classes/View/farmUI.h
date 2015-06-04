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

	//�����򣬼��뽨��ͼƬ����ť��ʱ����
	Sprite*	_buildBox;
	//�����Ĳ˵���ť
	Sprite*	_buttom1;
	Sprite*	_buttom2;
	Sprite* _buttom3;
	//�ɼ�CD��
	LoadingBar* _CDbar;
	//����CD��ʱ
	float _CDcount;

public:
	//���ڴ��洴����FarmUI
	static cocos2d::Vector<FarmUI*> _farmUIs;
	//�����������CD
	static std::vector<int> _buildCDs;

public:
	FarmUI();
	~FarmUI();

	virtual	bool init();
	CREATE_FUNC(FarmUI);

	//����������ť�Ļص�����
	void InitBuildBox(FarmBuildData* Fbuild, FarmController* _Delegate);
	//���°�ť��ʾ��Ϣ��
	void showInfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmController* _Delegate);
	//�����ɼ�����
	void fBuildCollect(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmUI* FUI, FarmController* _Delegate);
	//CD������
	void CDupdate(float delta);
	//������������
	void BuilldUpdate(cocos2d::Object* pSender, FarmBuildData* Fbuild, FarmController* _Delegate);
};




class GainBox : public Sprite
{
private:
	static GainBox* gainBox;

public:
	//��Ϣ��رհ�ť
	Sprite*	_closeButtom;
	//�رղ˵�
	Menu* _menu;
	//��Ϣ��
	Sprite*	_GainBox;

public:
	GainBox();
	~GainBox();

	static GainBox* getInstance();
	static void destroyInstance();

	virtual bool init();

	//������Ϣ��
	void hideGainBoxCallback(cocos2d::Object* pSender);
	void hideGainBox();
	//������Ϣ��
	void resetGainBox();
};

#endif