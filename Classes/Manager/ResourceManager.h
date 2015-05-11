
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

	//��ӵ���ͼƬ�����棬�Ǵ�ͼ
	Texture2D* addSingleImage(const std::string &filepath);
	//���һ����ͼ������
	void addBigImage(const std::string &plistPath, const std::string &imgPath);
	void addBigImage(const std::string &plistPath);

	//����һ��plist
	ValueMap readPlist(const std::string &plistPath);

	virtual bool init();
};

#endif