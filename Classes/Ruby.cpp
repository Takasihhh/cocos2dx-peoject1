#include"Ruby.h"


Ruby* Ruby::create(const std::string& filename)
{
	Ruby *sprite = new (std::nothrow) Ruby();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}


bool Ruby::initPos(float x, float y)
{
	this->setPosition(x, y);

	this->setAnchorPoint(Vec2(0, 0));
	this->setScale(70 / 96.0);


	return true;



}

/*
bool Ruby::ruby_ttf(int count)
{

	
	auto lab1 = LabelAtlas::create(
		std::to_string(1), "level_num.png", 37, 37, '0'
		);
	this->addChild(lab1);
	lab1->setPosition(Vec2(50, 50));
	lab1->setAnchorPoint(Vec2(0, 0.5));


	return true;
}*/