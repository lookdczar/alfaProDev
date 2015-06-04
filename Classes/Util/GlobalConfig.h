
#ifndef _GLOBAL1_CONFIG_H_
#define _GLOBAL1_CONFIG_H_

#include "cocos2d.h"





static class GlobalConfig 
{



public:


	static void resetRandom(int seed);
	static int getRandom(int minValue, int maxValue,  bool resetRandom);




};

#endif