#include "BigLevelLayer.h"
#include"small_level_scene.h"
#include "LoginScene.h"
#include "Game_data.h"





bool BigLevelLayer::init()
{

	if (!Layer::init())
	{
		return false;
	}

	//获取游戏窗口的大小  =》实际分辨率
	Size visibleSize = Director::getInstance()->getVisibleSize();
	//添加一个按钮
	auto back_1 = Button::create("CheckBack_1.png", "CheckBack_2.png", "CheckBack_1.png");
	this->addChild(back_1, 1);
	back_1->setPosition(Vec2(visibleSize.width*0.06, visibleSize.height*0.95));

	back_1->addTouchEventListener([&](Ref *ref, Widget::TouchEventType type)
	{
		auto login_scene = LoginScene::createScene();
		Director::getInstance()->replaceScene(login_scene);

	});
	//添加背景图
	auto bg_sp1 = Sprite::create("Select_background.jpg");
	bg_sp1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	bg_sp1->setScale(768 / 640.0);
	this->addChild(bg_sp1);
	//添加选关
	/*
	iceland_Portal.png
	desert_Portal.png
	forest_Portal.png
	*/
	auto btn_1 = Button::create("forest_Portal.png", "forest_Portal.png", "forest_Portal.png");
	auto btn_2 = Button::create("desert_Portal.png", "desert_Portal.png", "desert_Portal.png"); 
	auto btn_3 = Button::create("iceland_Portal.png", "iceland_Portal.png", "iceland_Portal.png");
	this->addChild(btn_1,2);
	this->addChild(btn_2,2);
	this->addChild(btn_3,2);
	btn_1->_ID = 1;
	btn_2->_ID = 2;
	btn_3->_ID = 3;


	//设定位置和大小
	btn_1->setScale(0.5);
	btn_2->setScale(0.5);
	btn_3->setScale(0.5);

	btn_1->setPosition(Vec2(visibleSize.width*0.25, visibleSize.height*0.5));
	btn_2->setPosition(Vec2(visibleSize.width*0.5, visibleSize.height*0.5));
	btn_3->setPosition(Vec2(visibleSize.width*0.75, visibleSize.height*0.5));

	//添加动作
	auto act = RepeatForever::create(
		Sequence::create(
		ScaleTo::create(1.0f, 0.65),
		ScaleTo::create(2.0f, 0.5),
		NULL
		)
		);

	auto act_fade = RepeatForever::create(
		Sequence::create(
		FadeTo::create(1.0f,125),
		FadeTo::create(2.0f,255),
		NULL
		)
		);

	//克隆动作
	auto act1 = act->clone();
	auto act2 = act->clone();

	auto act_fade1 = act_fade->clone();
	auto act_fade2 = act_fade->clone();

	//执行动作
	btn_1->runAction(act1);
	btn_2->runAction(act2);
	btn_3->runAction(act);

	btn_1->runAction(act_fade1);
	btn_2->runAction(act_fade2);
	btn_3->runAction(act_fade);

	btn_1->setTag(1);
	btn_2->setTag(2);
	btn_3->setTag(3);


	//添加触摸监听事件
	btn_1->addTouchEventListener(CC_CALLBACK_2(BigLevelLayer::change_choicelevel_scene,this));
	btn_2->addTouchEventListener(CC_CALLBACK_2(BigLevelLayer::change_choicelevel_scene, this));
	btn_3->addTouchEventListener(CC_CALLBACK_2(BigLevelLayer::change_choicelevel_scene, this));

	//添加兔子
	auto rabbit_sp = Sprite::create("rabbit/rabbit1.png");
	this->addChild(rabbit_sp,1);
	rabbit_sp->setPosition(-50, visibleSize.height*0.4);
	//添加帧动画
	rabbit_sp->runAction(this->create_rabbit_ani());
	//添加动作
	RepeatForever* rabbit_act = RepeatForever::create(
		Sequence::create(
		MoveTo::create(9.0f, Vec2(1600, 100)),
		MoveTo::create(0, Vec2(-50, visibleSize.height*0.4)),
		NULL
			 )
		);
	rabbit_sp->runAction(rabbit_act);
	return true;
}


void  BigLevelLayer::change_choicelevel_scene(Ref *ref, Widget::TouchEventType type)
{

	CCLOG("YOUR ID IS %i",ref->_ID);
	switch (ref->_ID)
	{

	case 1:Game_data::s_iCurBigLevel = 1;
		break;
	case 2:Game_data::s_iCurBigLevel = 2;
		break;
	case 3: Game_data::s_iCurBigLevel = 3;
		break;
	default:
		break;
	}
	auto smalllevelscene = small_level_scene::createScene();
	auto act1 = FadeIn::create(0.4f);
	this->runAction(act1);
	Director::getInstance()->replaceScene(smalllevelscene);

}

ActionInterval * BigLevelLayer::create_rabbit_ani()
{
	//创建动画配置
	Animation* rabbit_ani = Animation::create();
	char * frameName = "rabbit/rabbit";
	for (int i = 1; i <11 ; i++)
	{
 		char szName[128] = {};
		sprintf(szName, "%s%d.png", frameName , i);
		rabbit_ani->addSpriteFrameWithFileName(szName);
	}
	rabbit_ani->setDelayPerUnit(0.08f);
	//从第一张图开始播放
	rabbit_ani->setRestoreOriginalFrame(true);

	return RepeatForever::create(Animate::create(rabbit_ani));


}