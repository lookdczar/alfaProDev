#ifndef _FARMUI_H_
#define _FARMUI_H_

#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

class farmUI : public Node
{
public:

	//�����򣬼��뽨��ͼƬ����ť��ʱ����
	Sprite*	_buildBox;
	//�����Ĳ˵���ť
	Sprite*	_buttom1;
	Sprite*	_buttom2;
	//�ɼ�CD��
	LoadingBar* _CDbar;

public:
	farmUI();
	~farmUI();

	virtual	bool init();
	CREATE_FUNC(farmUI);

	//��ʾ��Ϣ��
	void showinfoBox();
	//������Ϣ��
	void hideinfoBox();

};

#endif