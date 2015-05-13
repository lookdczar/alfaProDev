#include "MenuScene.h"
#include "Manager\GameManager.h"
#include "Util\FileHelper.h"

USING_NS_CC;

bool MenuScene::init()
{ 
	if (!BaseScene::init())
		return false;

	//³õÊ¼»¯GameManager
	GameManager::getInstance();

	//¼ÓÔØcontroller
	menuController = MenuController::create();
	addChild(menuController);

// 	ValueMap map = GameManager::getInstance()->resManager->readPlist("test.plist");
// 
// 	//Value f = map["d"];
// 	//Value i = map["a"];
// 	//Value::Type t1 = f.getType();
// 	//Value::Type t2 = i.getType();
// 	//std::string s = f.asString();
// 	//const char* c = s.c_str();
// 	
// 	FileHelper::plistWriteFile(map, "test2.plist");

    return true;
}



