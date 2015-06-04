#include "GlobalConfig.h"


USING_NS_CC;



void GlobalConfig::resetRandom(int seed)
{
	if (seed != 0)
	{
		srand(seed);
		return;
	}
	struct timeval nowTimeval;
	gettimeofday(&nowTimeval, NULL);
	struct tm * tm;
	time_t time_sec;
	time_sec = nowTimeval.tv_sec;
	tm = localtime(&time_sec);
	unsigned long reed = tm->tm_sec * 1000 + tm->tm_min * 10 + tm->tm_hour;
	srand(reed);
}
int GlobalConfig::getRandom(int minValue, int maxValue, bool resetRandom)
{
	if (resetRandom)
	{
		struct timeval nowTimeval;
		gettimeofday(&nowTimeval, NULL);
		struct tm * tm;
		time_t time_sec;
		time_sec = nowTimeval.tv_sec;
		tm = localtime(&time_sec);
		unsigned long reed = tm->tm_sec * 1000 + tm->tm_min * 10 + tm->tm_hour;
		srand(reed);
	}
	return (CCRANDOM_0_1()*maxValue + minValue);
}

