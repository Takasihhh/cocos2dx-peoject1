#ifndef _GOBLIN_H_
#define _GOBLIN_H_

#include"cocos2d.h"
using namespace cocos2d;

#define LENGTH 70

class Goblin :public Sprite
{

public:

	static Goblin* create(const std::string& filename);

	bool initPos(float x, float y);



	float x, y;

	void playGobAni();
	void Goblin::move();


};







#endif