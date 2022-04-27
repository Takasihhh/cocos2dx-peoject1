#include "dragon_mon.h"


dragon_mon* dragon_mon::create(const std::string& filename)
{
	dragon_mon *sprite = new (std::nothrow) dragon_mon();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool dragon_mon::initPos(float x, float y)
{

	this->setPosition(x, y);

	this->setAnchorPoint(Vec2(0, 0));
	this->setScale(2*70 / 100.0);


	return true;
}

void dragon_mon::playDraAni()
{

	auto ani = Animation::create();
	char* frameName = "Monster/dulong_right";
	for (int i = 1; i <= 4; i++)
	{
		char szName[128] = {};
		sprintf(szName, "%s%d.png", frameName, i);
		ani->addSpriteFrameWithFileName(szName);
	}
	ani->setDelayPerUnit(0.12f);
	auto act = RepeatForever::create(Animate::create(ani));
	this->runAction(act);
}


void dragon_mon::move(){

	auto moveby = MoveBy::create(4.5f, Vec2(5 * LENGTH, 0));
	auto moveback = MoveBy::create(3.5f, Vec2(-(5 * LENGTH), 0));
	auto flip = FlipX::create(true);
	auto flip1 = FlipX::create(false);
	auto act = RepeatForever::create(Sequence::create(moveby, flip, moveback, flip1, NULL));

	this->runAction(act);

}



