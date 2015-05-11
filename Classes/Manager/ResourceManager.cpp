#include "ResourceManager.h"
USING_NS_CC;

ResourceManager::ResourceManager()
{
	texCache = Director::getInstance()->getTextureCache();
	sfCache = SpriteFrameCache::getInstance();
	init();
}


ResourceManager::~ResourceManager()
{
	texCache = nullptr;
	sfCache = nullptr;
	file = nullptr;
}

bool ResourceManager::init()
{
	texCache = Director::getInstance()->getTextureCache();
	sfCache = SpriteFrameCache::getInstance();
	file = FileUtils::getInstance();
	return true;
}

//��ӵ���ͼƬ���Ǵ�ͼ
Texture2D* ResourceManager::addSingleImage(const std::string &filepath)
{
	if(filepath.empty() || filepath.length()<1)
		return nullptr;
	return texCache->addImage(filepath);
}

//���һ����ͼ
void ResourceManager::addBigImage(const std::string &plistPath,const std::string &imgPath)
{
	if(plistPath.empty() || plistPath.length()<1)
		return;
	if(imgPath.empty() || imgPath.length()<1)
		return;
	sfCache->addSpriteFramesWithFile(plistPath, imgPath);
}

void ResourceManager::addBigImage(const std::string &plistPath)
{
	if(plistPath.empty() || plistPath.length()<1)
		return;
	sfCache->addSpriteFramesWithFile(plistPath);
}

//����һ��plist
ValueMap ResourceManager::readPlist(const std::string &plistPath)
{
	ValueMap plist;
	if(plistPath.empty() || plistPath.length()<1)
		return plist;
	plist  = file->getValueMapFromFile(plistPath);
	return plist;
}