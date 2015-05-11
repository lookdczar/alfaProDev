#ifndef __ADV_VIEW_H__
#define __ADV_VIEW_H__

#include "cocos2d.h"
#include "BaseView.h"

class AdvController;
class AdvAreaData;

class AdvView : public BaseView
{
private:
//	AdvController* controller;

public:
    virtual bool init();

	CREATE_FUNC(AdvView);

	//��ʾ������Ϣ
	void showAdvArea(const cocos2d::Vector<AdvAreaData*>& advInfos);

};

#endif 
