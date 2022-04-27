#include"small_level_scene.h"
#include"small_level_layer.h"

using namespace cocos2d;

USING_NS_CC;


Scene* small_level_scene::createScene()
{
	auto scene = Scene::create();
	auto layer = small_level_layer::create();
	scene->addChild(layer);
	return scene;

}