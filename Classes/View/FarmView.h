#ifndef __FARM_VIEW_H__
#define __FARM_VIEW_H__

#include "cocos2d.h"
#include "BaseView.h"

class FarmController;
class FarmBuildData;

class FarmView : public BaseView
{
public:

	virtual bool init();

	CREATE_FUNC(FarmView);

	//��ʾ������Ϣ
	void showAdvArea(const cocos2d::Vector<FarmBuildData*>& buildInfos);
};

#endif 