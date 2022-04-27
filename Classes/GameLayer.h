#ifndef __GAME_LAYER_H__
#define __GAME_LAYER_H__
#include "Tree_Mon.h"
#include"Goblin_Mon.h"
#include "cocos2d.h"
#include"Player.h"
#include"Ruby.h"
#include"dragon_mon.h"
#include "exit_node.h"

#include"point_board.h"

#include"Game_data.h"
#define LENGTH 70

class GameLayer : public cocos2d::Layer
{
public:

	virtual bool init();
	CREATE_FUNC(GameLayer);
	virtual bool onTouchBegan(cocos2d::Touch * touch, cocos2d::Event*ev);
	point_board* board;
	point_board* ruby_count;
	game_map * map;
	Player* player1;
	treeMon* treemon1;
	Goblin* goblin1;
	Ruby* ruby0;
	Ruby* ruby1;
	Ruby* ruby2;
	Ruby *key;
	Ruby *atf;
	dragon_mon * dragonmon1;
	exit_node * exitpoint;
	LabelAtlas *m_boxCountAtlas;

	
	//获取游戏窗口的大小  =》实际分辨率
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//update
	void update(float dt);
	void updatePlayer();
	void updateUI();
	void updatemap(int big_level, int small_level);
	void updatemon();
	void updateobj();
	void updatepoint_board();
	void update_crash();
	void update_level();

	virtual bool crashtest(Node* obj);

private:
	int m_iBoxcount = 0;
	bool isgetkey;
	int count = 0;
};

#endif // __TMX_LAYER_H__
