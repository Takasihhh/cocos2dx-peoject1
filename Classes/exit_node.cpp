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

	auto exit_ani = Animation::create();//创建一个动画节点

	char* framename = "trandoor/exit_";//定义文件字符串


	for (int i = 1; i <= 11; ++i)//拼接文件名
	{

		char szName[128] = {};


		sprintf(szName, "%s%d.png", framename, i);

		exit_ani->addSpriteFrameWithFileName(szName);//将文件名添加到节点

	}
	exit_ani->setDelayPerUnit(0.12f);//设置帧动画时间

	auto act = RepeatForever::create(Animate::create(exit_ani));

	this->runAction(act);
}