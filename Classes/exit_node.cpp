#include "exit_node.h"




exit_node* exit_node::create(const std::string& filename)
{

	exit_node *sprite = new (std::nothrow) exit_node();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;

}




bool exit_node::initPos(float x, float y)
{
	this->setPosition(x, y);

	this->setAnchorPoint(Vec2(0, 0));
	this->setScale(70 / 440.0);




	return true;



}



void exit_node::play_exit_ani()
{

	auto exit_ani = Animation::create();//����һ�������ڵ�

	char* framename = "trandoor/exit_";//�����ļ��ַ���


	for (int i = 1; i <= 11; ++i)//ƴ���ļ���
	{

		char szName[128] = {};


		sprintf(szName, "%s%d.png", framename, i);

		exit_ani->addSpriteFrameWithFileName(szName);//���ļ�����ӵ��ڵ�

	}
	exit_ani->setDelayPerUnit(0.12f);//����֡����ʱ��

	auto act = RepeatForever::create(Animate::create(exit_ani));

	this->runAction(act);
}