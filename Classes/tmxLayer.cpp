#include "tmxLayer.h"
#include "cocostudio/CocoStudio.h"

#include "Tree_Mon.h"
#include"Goblin_Mon.h"
#include "ui/CocosGUI.h"  //���밴ť��guiͷ�ļ�
#include"Player.h"
using namespace cocos2d::ui;

USING_NS_CC;

bool tmxLayer::init()
{

	if (!Layer::init())
	{
		return false;
	}
	//��֡��ʱ��
	this->scheduleUpdate();
	//��ȡ��Ϸ���ڵĴ�С  =��ʵ�ʷֱ���
	Size visibleSize = Director::getInstance()->getVisibleSize();
//��ӵ�ͼ
	auto map = TMXTiledMap::create("Map/Map1_2.tmx");
	this->addChild(map);
	//��ȡ������
	auto object0 = map->getObjectGroup("object0");
	//������
	auto player = object0->getObject("player");

	//��ȡ��������
	float x = player["x"].asFloat();
	float y = player["y"].asFloat();
	
	////
	//auto playerNode = Sprite::create("player/PlayerDown_0.png");
	//this->addChild(playerNode);
	//playerNode->setPosition(x, y);
	//playerNode->setAnchorPoint(Vec2(0, 0));

   this->player1 = Player::create("player/PlayerDown_0.png");
	this->addChild(player1);
	player1->initPos(x,y);
	player1->playAni(PLAYERDIR::DWON);
	//��������
	//��ȡ������
	auto object3 = map->getObjectGroup("object3");
	//�������
	auto treemonobj = object3->getObject("treemon_1");
	auto goblinobj = object3->getObject("goblin_1");

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


	//��ӱ�ʯ
	//��ȡ������
	auto object2 = map->getObjectGroup("object2");
	//�������
	auto rubyobj = object2->getObject("box_1");

	//��ȡ��������
	float x3 = rubyobj["x"].asFloat();
	float y3 = rubyobj["y"].asFloat();

	this->ruby1 = Ruby::create("box1.png");
	this->addChild(ruby1);
	ruby1->initPos(x3, y3);

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

	crashtest(goblin1);
	crashtest(treemon1);
	return true;
}


bool tmxLayer::onTouchBegan(Touch * touch, Event*ev){
	Point playerPos = player1->getPosition();
	Point touPos = touch->getLocation();
	float xDis = touPos.x - playerPos.x;
	float yDis = touPos.y - playerPos.y;

	if (xDis*xDis > yDis*yDis){
		//���ҷ����ƶ�

		//��Ŀ���㷨
		player1->move(xDis < 0 ? LEFT: RIGHT);
	}
	else
	{
		//���·����ƶ�
		player1->move(yDis < 0 ? DWON : UP);

	}
	return true;
}


bool tmxLayer::crashtest(Node* obj)


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
void tmxLayer::update(float dt)
{
	CCLOG("time%f", dt);
	if (crashtest(treemon1))
	{
		CCLOG("ײ��������");

	tmxLayer::init();

	}
	if (crashtest(goblin1))
	{
		CCLOG("ײ���粼����");
		tmxLayer::init();
	}




}