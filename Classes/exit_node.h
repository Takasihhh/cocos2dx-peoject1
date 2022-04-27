#ifndef __EXIT_NODE__
#define __EXIT_NODE__



#include "cocos2d.h"
using namespace cocos2d;

class exit_node :public Sprite
{
public:
	static exit_node* create(const std::string& filename);

	bool initPos(float x, float y);

	void play_exit_ani();

};









#endif