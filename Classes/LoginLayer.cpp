#include"LoginLayer.h"
#include"BigLevelScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"  //引入按钮的gui头文件
using namespace cocos2d::ui;


bool LoginLayer::init()
{

	if (!Layer::init())
	{
		return false;
	}

	//获取游戏窗口的大小  =》实际分辨率
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//添加一个按钮
	auto btn_1 = Button::create("StartGame_botton_normal.png", "StartGame_botton_press.png", "StartGame_botton_normal.png");
	this->addChild(btn_1,1);
	btn_1->setPosition(Vec2(visibleSize.width*0.8, visibleSize.height*0.7));

	btn_1->addTouchEventListener([&](Ref *ref, Widget::TouchEventType type)
	{
		auto big_level_scene = BigLevelScene::createScene();
		auto newScne = TransitionFadeUp::create(0.6f, big_level_scene);
		cocos2d::Director::getInstance()->replaceScene(newScne);


	});
	//添加背景图
	auto bg_sp = Sprite::create("mainbg.png");
    bg_sp->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(bg_sp);



	//添加logo
	auto logo_sp = Sprite::create("LOGO.png");
	logo_sp->setPosition(Vec2(visibleSize.width / 3.8, visibleSize.height / 1.3));
	logo_sp->setScale(0.4);
	this->addChild(logo_sp);

	//添加太阳
	auto sun_sp = Sprite::create("sunshine.png");
	sun_sp->setAnchorPoint(Vec2(0,1));
	sun_sp->setPosition(0, visibleSize.height);
	sun_sp->setScale(2);
	this->addChild(sun_sp);

	//添加动态光照
	auto bullet_sp = Sprite::create("sun.png");
	bullet_sp->setAnchorPoint(Vec2(0, 1));
	bullet_sp->setPosition(0, visibleSize.height);
	bullet_sp->setScale(2);
	bullet_sp->setOpacity(100);//不透明度0-255

	bullet_sp->runAction(RepeatForever::create(RotateBy::create(10.0f, 30.0f)));
	this->addChild(bullet_sp);

	return true;

}