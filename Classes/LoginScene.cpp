#include "LoginScene.h"

#include "ui/CocosGUI.h"  //���밴ť��guiͷ�ļ�
#include"LoginLayer.h"
//#include "LoginLayer.h"


using namespace cocos2d::ui;

USING_NS_CC;

Scene* LoginScene::createScene()
{
	auto scene = Scene::create();
	auto layer = LoginLayer::create();
	scene->addChild(layer);
	return scene;
}

