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
	//��Ϣ��رհ�ť
	Sprite*	_closeButtom;
	//�رղ˵�
	Menu* _menu;
	//��Ϣ��
	Sprite*	_infoBox;
public:
	infoBox();
	~infoBox();

	static infoBox* getInstance();
	static void destroyInstance();

	virtual bool init();

	//������Ϣ��
	void hideInfoBox(cocos2d::Object* pSender);
	//������Ϣ��
	void resetInfoBox();
};

#endif