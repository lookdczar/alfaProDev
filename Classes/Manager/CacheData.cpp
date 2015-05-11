#include "CacheData.h"
#include "Util\CommonHelper.h"

CacheDataM::CacheDataM()
{
	hasRead = false;
}


CacheDataM::~CacheDataM()
{
}

CacheDataM* CacheDataM::create(const ValueMap& map)
{ 
	CacheDataM* pRet = new(std::nothrow) CacheDataM();
	if (pRet && pRet->init(map))
    { 
        pRet->autorelease(); 
        return pRet; 
    } 
    else 
    { 
        delete pRet; 
        pRet = NULL; 
        return NULL; 
    } 
}

bool CacheDataM::init()
{
	return true;
}

bool CacheDataM::init(const ValueMap& map)
{
	bindResPath(map);
	return true;
}


//°ó¶¨×ÊÔ´path
void CacheDataM::bindResPath(const ValueMap& map)
{

	if (CommonHelper::ValueMapContainsKey(map, P_IMG_S))
	{
		imgPathArr_S = map.at(P_IMG_S).asValueVector();
	}
	if (CommonHelper::ValueMapContainsKey(map, P_IMG_B))
	{
		imgPath_B = map.at(P_IMG_B).asString();
	}

	if (CommonHelper::ValueMapContainsKey(map, P_DATA_PLIST))
	{
		dataPath = map.at(P_DATA_PLIST).asString();
	}
	
	
}


