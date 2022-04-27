#include "Gamescene.h"

#include "ui/CocosGUI.h"  //引入按钮的gui头文件
#include"GameLayer.h"


//#include "LoginLayer.h"


using namespace cocos2d::ui;

USING_NS_CC;

Scene* Gamescene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}

