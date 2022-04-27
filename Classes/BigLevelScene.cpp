#include"BigLevelScene.h"
#include"BigLevelLayer.h"
using namespace cocos2d::ui;

USING_NS_CC;

Scene* BigLevelScene::createScene(){

	auto scene = Scene::create();
    auto layer =BigLevelLayer::create();
	scene->addChild(layer);
	return scene;


}