#ifndef __TMX_LAYER_H__
#define __TMX_LAYER_H__
#include "Tree_Mon.h"
#include"Goblin_Mon.h"
#include "cocos2d.h"
#include"Player.h"
#include"Ruby.h"

#define LENGTH 70

class tmxLayer : public cocos2d::Layer
{
public:

	virtual bool init();
	CREATE_FUNC(tmxLayer);
	virtual bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event*ev);
	Player* player1;
	treeMon* treemon1;
	Goblin* goblin1;
	Ruby* ruby1;
	void update(float dt);

	

	virtual bool crashtest(Node* obj);


};

#endif // __TMX_LAYER_H__
