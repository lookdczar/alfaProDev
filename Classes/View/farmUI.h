#ifndef _FARMUI_H_
#define _FARMUI_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <vector>

USING_NS_CC;
using namespace ui;

class FarmBuildData;
class infoBox;

class FarmUI : public Node
{
public:

	//�����򣬼��뽨��ͼƬ����ť��ʱ����
	Sprite*	_buildBox;
	//�����Ĳ˵���ť
	Sprite*	_buttom1;
	Sprite*	_buttom2;
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
	void InitBuildBox(FarmBuildData* Fbuild);
	//���°�ť��ʾ��Ϣ��
	void showInfoBox(cocos2d::Object* pSender, FarmBuildData* Fbuild);
	//������Ϣ��
	void hideInfoBox();
	//�����ɼ�����
	void fBuildCollect(cocos2d::Object* pSender, FarmUI* FUI);
	//CD������
	void CDupdate(float delta);
};

#endif