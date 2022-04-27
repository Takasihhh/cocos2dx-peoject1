#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "game_map.h"
#include"cocos2d.h"
using namespace cocos2d;

enum PLAYERDIR
{
	UP,
	DWON,
	LEFT,
    RIGHT


};


class Player :public Sprite
{

public:

	static Player* create(const std::string& filename);

	bool initPos(float x, float y);

	float x, y;

	void playAni(PLAYERDIR dir);
	void Player::move(game_map *map,const char* layerName,const PLAYERDIR& dir);
	
	PLAYERDIR  player_dir;

private: 
	float fSpeed;
	bool bIstay;

	void move_over_call_back();


};







#endif