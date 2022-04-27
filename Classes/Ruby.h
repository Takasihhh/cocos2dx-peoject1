#ifndef _RUBY_H_
#define _RUBY_H_

#include"cocostudio\CocoStudio.h"
#include "cocos2d.h"
using namespace cocos2d;

class Ruby :public Sprite
{
public:
	static Ruby* create(const std::string& filename);

	bool initPos(float x, float y);

	//bool ruby_ttf(int count);
};






#endif