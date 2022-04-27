#include"Loadinglayer.h"
#include"LoginScene.h"
using namespace cocos2d::ui;
USING_NS_CC;

bool LoadingLayer::init()
{
	if (!Layer::init())
	{
		return false;
		
	}
	
	this->scheduleOnce(schedule_selector(LoadingLayer::change_to_LoginScene),0.5f);
	return true;

}
void LoadingLayer::change_to_LoginScene(float time)
{


	auto loginScene = LoginScene::createScene();
	auto fadein = FadeIn::create(0.5f);
	this->runAction(fadein);
	cocos2d::Director::getInstance()->replaceScene(loginScene);




}
