#include "Gamescene.h"

#include "ui/CocosGUI.h"  //���밴ť��guiͷ�ļ�
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

