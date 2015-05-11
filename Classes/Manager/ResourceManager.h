
#ifndef _RESOURCE_MANAGER_H_
#define _RESOURCE_MANAGER_H_

#include "cocos2d.h"
#include "BaseManager.h"

USING_NS_CC;

class ResourceManager : public BaseManager
{

private:
	cocos2d::TextureCache* texCache;
	cocos2d::SpriteFrameCache* sfCache;
	cocos2d::FileUtils* file;

public:
	ResourceManager();
	~ResourceManager();

	//添加单个图片到缓存，非大图
	Texture2D* addSingleImage(const std::string &filepath);
	//添加一个大图到缓存
	void addBigImage(const std::string &plistPath, const std::string &imgPath);
	void addBigImage(const std::string &plistPath);

	//加载一个plist
	ValueMap readPlist(const std::string &plistPath);

	virtual bool init();
};

#endif