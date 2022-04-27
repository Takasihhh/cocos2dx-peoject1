#ifndef _TREE_MON_H_
#define _TREE_MON_H_

#include"cocos2d.h"
using namespace cocos2d;



class treeMon :public Sprite
{

public:

	static treeMon* create(const std::string& filename);

	bool initPos(float x, float y);



	float x, y;

	void playTreeAni();

};







#endif