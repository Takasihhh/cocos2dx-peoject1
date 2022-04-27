#include "Player.h"

#define length 16
#define width 10

Player* Player::create(const std::string& filename)
{
	Player *sprite = new (std::nothrow) Player();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool Player::initPos(float x, float y)
{

	this->setPosition(x, y);

	this->setAnchorPoint(Vec2(0, 0));
	this->setScale(70 / 96.0);


	return true;
}

void Player::playAni(PLAYERDIR dir)
{
	
	Animation *ani = Animation::create();
	//1 ио  2 об 3 вС 4 ср
	char * frameName = "player/PlayerDown_";
	switch (dir)
	{
	case PLAYERDIR::UP:
		frameName = "player/PlayerUp_";
		break;
	case PLAYERDIR::DWON:
		"player/PlayerDown_";
		break;
	case PLAYERDIR::LEFT:
		this->setFlippedX(false);
		frameName = "player/PlayerLeft_";
		break;
	case PLAYERDIR::RIGHT:
		this->setFlippedX(true);
		frameName = "player/PlayerLeft_";
		break;
	default:
		break;
	}
	for (int i = 0; i < 4; i++){
		char szName[128] = {};
		sprintf(szName, "%s%d.png", frameName, i);
		ani->addSpriteFrameWithFileName(szName);
	}
	ani->setDelayPerUnit(0.12f);
	auto act = RepeatForever::create(Animate::create(ani));
	this->stopAllActions();	
	this->runAction(act);


}





void Player::move(game_map *map, const char* layerName, const PLAYERDIR& dir){
	
	if (!bIstay)
		return;
	bIstay = false;
	fSpeed = 1000.0f;
	playAni(dir);
	Vec2 heroPos = this->getPosition();
	Point targetPos = map->getTargetPos(layerName, heroPos, (CHECKDIR)dir);

	float dt = targetPos.getDistance(heroPos) / fSpeed;

	this->runAction(Sequence::create(MoveTo::create(dt, targetPos), CallFunc::create(this, callfunc_selector(Player::move_over_call_back)), NULL));

	

}



void Player::move_over_call_back()
{

	bIstay = true;

}