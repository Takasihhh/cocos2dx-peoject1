#ifndef __DRAGON_MON__
#define __DRAGON_MON__

#include"cocos2d.h"
using namespace cocos2d;

#define LENGTH 70

class dragon_mon :public Sprite
{

public:

	static dragon_mon* create(const std::string& filename);

	bool initPos(float x, float y);



	float x, y;

	void playDraAni();
	void dragon_mon::move();


};







#endif