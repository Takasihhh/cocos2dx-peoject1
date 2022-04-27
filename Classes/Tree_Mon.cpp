#include "Tree_Mon.h"


treeMon* treeMon::create(const std::string& filename)
{
	treeMon *sprite = new (std::nothrow) treeMon();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool treeMon::initPos(float x, float y)
{

	this->setPosition(x, y);

	this->setAnchorPoint(Vec2(0, 0));
	this->setScale(70 / 96.0);


	return true;
}

void treeMon::playTreeAni()
{

	auto scaleto = ScaleTo::create(0.35f, 1.5f);
	auto scaleto1 = ScaleTo::create(0.2f, 1.0f);
	
	auto act = RepeatForever::create(Sequence::create(scaleto, scaleto1,NULL));
	this->runAction(act);
	
	}
