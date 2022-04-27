#include "Goblin_Mon.h"


Goblin* Goblin::create(const std::string& filename)
{
	Goblin *sprite = new (std::nothrow) Goblin();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool Goblin::initPos(float x, float y)
{

	this->setPosition(x, y);

	this->setAnchorPoint(Vec2(0, 0));
	this->setScale(70 / 96.0);


	return true;
}

void Goblin::playGobAni()
{

	auto ani = Animation::create();
	char* frameName = "Monster/gebulin_right";
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


void Goblin::move(){

	auto moveby = MoveBy::create(3.0f, Vec2(6 * LENGTH, 0));
	auto moveback = MoveBy::create(3.0f, Vec2(-(6 * LENGTH), 0));
	auto flip = FlipX::create(true);
	auto flip1 = FlipX::create(false);
	auto act = RepeatForever::create(Sequence::create(moveby, flip, moveback, flip1, NULL));

	this->runAction(act);

}



