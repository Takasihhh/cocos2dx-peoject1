#pragma once
#pragma execution_charater_set("utf-8")

#define level_size 5
#include "Gamescene.h"
#include "BigLevelScene.h"
#include"LoginScene.h"
#include"small_level_layer.h"
#include "Game_data.h"





bool small_level_layer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	 
	Size visiblesize = Director::getInstance()->getVisibleSize();

	if (Game_data::s_iCurBigLevel == 1)
	{
	
		Sprite* ForestBgm = Sprite::create("map_Forest.jpg");
		ForestBgm->setPosition(visiblesize / 2);
		ForestBgm->setScaleX(1.5f);
		this->addChild(ForestBgm);
	}
	if (Game_data::s_iCurBigLevel == 2){
		Sprite* ForestBgm = Sprite::create("map_Desert.jpg");
		ForestBgm->setPosition(Vec2(1334 / 2, 750 / 2));
		ForestBgm->setScale(1.1f);
		this->addChild(ForestBgm);
	}
	if (Game_data::s_iCurBigLevel == 3){
		Sprite* ForestBgm = Sprite::create("map_Iceland.jpg");
		ForestBgm->setPosition(visiblesize / 2);
		ForestBgm->setScaleX(1.5f);
		this->addChild(ForestBgm);
	}

	//背景图精灵
	/*auto bg_sp1 = Sprite::create("map_Forest.jpg");
	bg_sp1->setScale(768 / 640.0);
	bg_sp1->setPosition(Vec2(visiblesize.width / 2, visiblesize.height / 2));
	this->addChild(bg_sp1); */
	//添加返回按钮
	auto back_1 = Button::create("CheckBack_1.png", "CheckBack_2.png", "CheckBack_1.png");
	this->addChild(back_1, 1);
	back_1->setPosition(Vec2(visiblesize.width*0.06, visiblesize.height*0.95));

	back_1->addTouchEventListener([&](Ref *ref, Widget::TouchEventType type)
	{
		auto big_level_scene = BigLevelScene::createScene();
		Director::getInstance()->replaceScene(big_level_scene);

	});

	//添加按钮
	for (int i = 0; i < level_size; i++)
	{
		//选关
		auto btn_1 = Button::create("level.png", "level.png", "level.png"); 
		this->addChild(btn_1);
		btn_1->setScale(0.7);
		btn_1->setTag(i + 1);
		btn_1->addTouchEventListener(CC_CALLBACK_2(small_level_layer::change_choicelevel_scene, this));
		float x = visiblesize.width*0.25 + i % 5 * 150;
		float y = visiblesize.height / 2;

		CCLOG("---%i---x--%f", i, x);
		CCLOG("------%i----y--%f", i, y);
		btn_1->setPosition(Vec2(x, y));
		

		//星星
		auto star_sp1 = Sprite::create("xingxing.png");
		auto star_sp2 = Sprite::create("xingxing.png");
		auto star_sp3 = Sprite::create("xingxing.png");

		this->addChild(star_sp1);
		this->addChild(star_sp2);
		this->addChild(star_sp3);

		star_sp1->setScale(0.5);
		star_sp2->setScale(0.5);
		star_sp3->setScale(0.5);

		star_sp1->setPosition(x-40,y-48);
		star_sp2->setPosition(x , y - 63);
		star_sp3->setPosition(x +40, y - 48);


		//创建艺术字   显示的文本字符串 图片路径 单个字体大小 第一个字体
		LabelAtlas* lab = LabelAtlas::create(
			std::to_string(i + 1), "level_num.png", 37, 37, '0'
			);
		this->addChild(lab);
		lab->setAnchorPoint(Vec2(0, 0.5));
		lab->setPosition(Vec2(x-20,y));
		
	}




	return true;
}

void small_level_layer::change_choicelevel_scene(Ref *ref, Widget::TouchEventType type)
{
	CCLOG("YOUR ID IS %i", ref->_ID);
	Button * btn = (Button *)ref;
	Game_data::s_iCurSmallLevel = btn->getTag();
	auto gamescene = Gamescene::createScene();
	auto act1 = FadeIn::create(0.4f);
	this->runAction(act1);
	Director::getInstance()->replaceScene(gamescene);

}