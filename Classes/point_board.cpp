#include "point_board.h"

#include"GameLayer.h"



point_board* point_board::create(const std::string& filename)
{
	point_board *sprite = new (std::nothrow) point_board();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}



bool point_board::init_ui()
{

	


	
	/*auto board_sp = Sprite::create("right_bg.png");
	this->addChild(board_sp);*/
	this->setPosition(Vec2((5*visibleSize.width/6)+10.0 , (visibleSize.height / 16) - 50.0));
	this->setAnchorPoint(Vec2(0, 0));

	
	/*auto ruby_count = Sprite::create("UI_GreenBox.png");
	this->addChild(ruby_count);
	ruby_count->setPosition(Vec2(visibleSize.width *0.8, visibleSize.height *0.2));
	ruby_count->setScale(5.0f);
	ruby_count->setAnchorPoint(Vec2(0, 0));
	*/


	return true;

}
bool point_board::init_cout()
{
	//Size visibleSize = Director::getInstance()->getVisibleSize();


	/*auto ruby_count = Sprite::create("UI_GreenBox.png");
	this->addChild(ruby_count);*/
	this->setPosition(Vec2(visibleSize.width *0.9, visibleSize.height *0.70));
	this->setAnchorPoint(Vec2(0, 0));


	return true;
}



bool point_board::init_btn()
{

	auto btn_back = Button::create("botton_back1.png", "botton_back1.png", "botton_back1.png");
	this->addChild(btn_back);
	btn_back->setAnchorPoint(Vec2(0, 0));
	btn_back->setPosition(Vec2((visibleSize.width *0.90)-35.0, visibleSize.height *0.20));
	


	btn_back->addTouchEventListener([&](Ref *ref, Widget::TouchEventType type)
	{
		auto big_level_scene = BigLevelScene::createScene();
		auto newScne = TransitionFadeUp::create(0.6f, big_level_scene);
		cocos2d::Director::getInstance()->replaceScene(newScne);	
	});
	

	return true;


}
