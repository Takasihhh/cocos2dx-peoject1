#include "GameLayer.h"
#include "cocostudio/CocoStudio.h"

#include "win_layer.h"
#include "Tree_Mon.h"
#include"Goblin_Mon.h"
#include "ui/CocosGUI.h"  //���밴ť��guiͷ�ļ�
#include"Player.h"
using namespace cocos2d::ui;

USING_NS_CC;

bool GameLayer::init()
{
	
	if (!Layer::init())
	{
		return false;
	}
	//��֡��ʱ��
	this->scheduleUpdate();


	//���ø��º���
	this->updateUI();


	//�������㴥��
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	////����������
	//Animation * ani = Animation::create();
	//for (int i = 0; i < 4; i++)
	//{
	//	char szname[128] = { 0 };
	//	sprintf(szname, "%s%d.png", "player/PlayerDown_", i);
	//	ani->addSpriteFrameWithFileName(szname);
	//	ani->setDelayPerUnit(0.1f);
	//	ani->setRestoreOriginalFrame(true);
	//}
	////����ִ���������
	//playerNode->runAction(RepeatForever::create(Animate::create(ani)));
	////playerNode->runAction(Repeat::create(Animate::create(ani), 10));
	isgetkey = false;
	ParticleRain *rain = ParticleRain::create();
	this->addChild(rain);

	return true;
}

//�浵
void GameLayer::update_level()
{

	m_iBoxcount = 0;
	const char* strBoxCount = String::createWithFormat("%d", m_iBoxcount)->getCString();
	m_boxCountAtlas = LabelAtlas::create(strBoxCount, "level_num.png", 37, 37, '0');
	ruby_count->addChild(m_boxCountAtlas);
	m_boxCountAtlas->setPosition(Vec2(0, 6.0f));
	m_boxCountAtlas->setScale(0.7f);





}

//��ײ����
void GameLayer::update_crash()
{


	crashtest(goblin1);
	crashtest(treemon1);
	crashtest(dragonmon1);
	crashtest(ruby0);
	crashtest(ruby1);
	crashtest(ruby2);
	crashtest(key);



}




bool GameLayer::onTouchBegan(Touch * touch, Event*ev){
	Point playerPos = player1->getPosition();
	Point touPos = touch->getLocation();
	float xDis = touPos.x - playerPos.x;
	float yDis = touPos.y - playerPos.y;

	if (xDis*xDis > yDis*yDis){
		//���ҷ����ƶ�

		//��Ŀ���㷨
		player1->move(map,"walkLayer",xDis < 0 ? LEFT : RIGHT);
	}
	else
	{
		//���·����ƶ�
		player1->move(map, "walkLayer", yDis < 0 ? DWON : UP);

	}
	return true;
}


bool GameLayer::crashtest(Node* obj)


{
	float xDis = player1->getPositionX() - obj->getPositionX();
	float yDis = player1->getPositionY() - obj->getPositionY();


	if (obj != NULL)
	{

		if (abs(xDis) < (LENGTH / 2) && abs(yDis) < (LENGTH / 2))
		{
			return true;
		}
		else
			return false;
	}
}




void  GameLayer::updatemap(int big_level, int small_level)
{
	//���سɹ��Ƴ�
	if (!this->map)
	{
		this->map->removeFromParent();
		this->map = nullptr;
	}
	//��ӵ�ͼ
	char map_str[128] = {};

	sprintf(map_str, "Map/Map%i_%i.tmx", big_level, small_level);
	this->map = game_map::create(map_str);
	this->addChild(map);


}
void  GameLayer::updatePlayer()
{

	//��ȡ������
	auto object0 = map->getObjectGroup("object0");
	//������
	auto player = object0->getObject("player");

	//��ȡ��������
	float x = player["x"].asFloat();
	float y = player["y"].asFloat();

	//auto playerNode = Sprite::create("player/PlayerDown_0.png");
	//this->addChild(playerNode);
	//playerNode->setPosition(x, y);
	//playerNode->setAnchorPoint(Vec2(0, 0));

	this->player1 = Player::create("player/PlayerDown_0.png");
	this->addChild(player1);
	player1->initPos(x, y);
	player1->playAni(PLAYERDIR::DWON);

	


}

void GameLayer::updatepoint_board()
{

	this->board = point_board::create("right_bg.png");
	this->ruby_count = point_board::create("UI_GreenBox.png");
	this->addChild(board);
	this->addChild(ruby_count);
	this->board->init_ui();
	this->ruby_count->init_cout();
	//init_btn
		auto btn_re = new point_board  ;
		this->addChild(btn_re);
		btn_re->init_btn();
		auto btn_restart = Button::create("botton_Restart1.png", "botton_Restart1.png", "botton_Restart2.png");
		this->addChild(btn_restart);
		btn_restart->setAnchorPoint(Vec2(0, 0));
		btn_restart->setPosition(Vec2((visibleSize.width*0.90) - 35.0, visibleSize.height *0.40));

		btn_restart->addTouchEventListener([&](Ref * ref, Widget::TouchEventType type)
		{
			
			GameLayer::init();
		});


}



void GameLayer::updatemon()
{
	

	//��������
	//��ȡ������
	auto object3 = map->getObjectGroup("object3");
	//�������
	auto treemonobj = object3->getObject("trap");
	auto goblinobj = object3->getObject("mon_1");
	auto dragonobj = object3->getObject("mon_2");
	//��ȡ��������
	float x1 = treemonobj["x"].asFloat();
	float y1 = treemonobj["y"].asFloat();


	this->treemon1 = treeMon::create("forest_trap.png");
	this->addChild(treemon1);
	treemon1->initPos(x1, y1);
	treemon1->playTreeAni();


	//��Ӹ粼��
	float x2 = goblinobj["x"].asFloat();
	float y2 = goblinobj["y"].asFloat();

	this->goblin1 = Goblin::create("Monster/gebulin_left1.png");
	this->addChild(goblin1);
	goblin1->initPos(x2, y2);
	goblin1->playGobAni();
	goblin1->move();

	//��ӷ���
  float x3 = dragonobj["x"].asFloat();
	float y3 = dragonobj["y"].asFloat();

	this->dragonmon1 = dragon_mon::create("Monster/dulong_right1.png");
	this->addChild(dragonmon1);
	dragonmon1->initPos(x3, y3);
	dragonmon1->playDraAni();
	dragonmon1->move();





}

void GameLayer::updateobj()
{
	//��ӱ�ʯ
	//��ȡ������
	auto object2 = map->getObjectGroup("object2");
	//���
	auto rubyobj0 = object2->getObject("box_1");

	//��ȡ��������
	float x0 = rubyobj0["x"].asFloat();
	float y0 = rubyobj0["y"].asFloat();

	this->ruby0 = Ruby::create("box1.png");
	this->addChild(ruby0);
	ruby0->initPos(x0, y0);
  //��ʯ��
	auto rubyobj1 = object2->getObject("box_2");

	//��ȡ��������
	float x1 = rubyobj1["x"].asFloat();
	float y1 = rubyobj1["y"].asFloat();

	this->ruby1 = Ruby::create("box1.png");
	this->addChild(ruby1);
	ruby1->initPos(x1, y1);
	//��ʯ��
	auto rubyobj2 = object2->getObject("box_3");

	//��ȡ��������
	float x3 = rubyobj2["x"].asFloat();
	float y3 = rubyobj2["y"].asFloat();

	this->ruby2 = Ruby::create("box1.png");
	this->addChild(ruby2);
	ruby2->initPos(x3, y3);

	//��ӳ���
	//��ȡ������
	auto object1 = map->getObjectGroup("object1");
	auto exitobj = object1->getObject("exit");

	//��ȡ��������

	float x2 = exitobj["x"].asFloat();
	float y2 = exitobj["y"].asFloat();

	this->exitpoint = exit_node::create("trandoor/exit_1.png");
	this->addChild(exitpoint);
	exitpoint->initPos(x2, y2);
	exitpoint->play_exit_ani();

	//���Կ��
	auto keyobj = object1->getObject("key");

	//��ȡ��������
	float x4 = keyobj["x"].asFloat();
	float y4 = keyobj["y"].asFloat();

	this->key = Ruby::create("key.png");
	this->addChild(key);
	key->initPos(x4, y4);
	key->setAnchorPoint(Vec2(0, 0));
}


void GameLayer::updateUI()
{
	
	this->updatemap(Game_data::s_iCurBigLevel, Game_data::s_iCurSmallLevel);
	this->updatepoint_board();
	this->updatePlayer();
	this->updatemon();
	this->updateobj();
	this->update_crash();

}

void GameLayer::update(float dt)
{
	//CCLOG("time%f", dt);
	if (crashtest(treemon1))
	{
		CCLOG("ײ��������");

		GameLayer::init();

	}
	if (crashtest(goblin1))
	{
		CCLOG("ײ���粼����");
		GameLayer::init();
	}

	if (crashtest(dragonmon1))
	{
		CCLOG("ײ��������");
		GameLayer::init();
	}
	if (crashtest(ruby0))
	{
		CCLOG("�õ���ʯ��");
		m_iBoxcount++;
		auto moveto =MoveTo::create(0.5f, Vec2(visibleSize.width *0.9, visibleSize.height *0.70));
		auto scaleto = ScaleTo::create(0.12f, 2.0f);
		auto act = Sequence::create(scaleto, moveto, NULL);
		ruby0->runAction(act);
	
	}
	if (crashtest(ruby1))
	{
		CCLOG("�õ���ʯ��");
		m_iBoxcount++;
		auto moveto = MoveTo::create(0.5f, Vec2(visibleSize.width *0.9, visibleSize.height *0.70));
		auto scaleto = ScaleTo::create(0.12f, 2.0f);
		auto act = Sequence::create(scaleto, moveto, NULL);
		ruby1->runAction(act);
		
	}
	if (crashtest(ruby2))
	{
		CCLOG("�õ���ʯ��");
		m_iBoxcount++;
		auto moveto = MoveTo::create(0.5f, Vec2(visibleSize.width *0.9, visibleSize.height *0.70));
		auto scaleto = ScaleTo::create(0.12f, 2.0f);
		auto act = Sequence::create(scaleto, moveto, NULL);
		ruby2->runAction(act);
	
	}
	if (crashtest(key))
	{
		CCLOG("�õ�Կ����");
	//	Vec2((visibleSize.width*0.45) - 3.0f, (visibleSize.height*0.67) - 5.0f)
		isgetkey = true;
		auto hide = Hide::create();
		auto scaleto = ScaleTo::create(0.5f, 1.25f);
		auto show = Show::create();
		auto place = Place::create(Vec2((visibleSize.width*0.90) + 13.0f, visibleSize.height*0.55));
		auto act = Spawn::create(hide, scaleto, place, show, NULL);
		key->runAction(act);

	}
	if (crashtest(exitpoint))
	{

		if (isgetkey)
		{
			int oldNum = Game_data::get_starnum(Game_data::s_iCurBigLevel, Game_data::s_iCurSmallLevel);
			int passCount = Game_data::getpass_count(Game_data::s_iCurBigLevel);
			if (Game_data::s_iCurSmallLevel >= passCount)
			{
				passCount++;
				Game_data::set_passvount(Game_data::s_iCurBigLevel, passCount);

			}
			if (m_iBoxcount > oldNum)
			{
				Game_data::save_star_nums(Game_data::s_iCurBigLevel, Game_data::s_iCurBigLevel, m_iBoxcount);
			}

			isgetkey = false;
			/**/this->addChild(win_layer::create(m_iBoxcount));
			
		}
	}


}