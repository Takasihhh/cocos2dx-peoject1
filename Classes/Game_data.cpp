#pragma once
#pragma execution_charater_set("utf-8")


#include"Game_data.h"


int Game_data::s_iCurSmallLevel = 1;
int Game_data::s_iCurBigLevel = 1;

Game_data * Game_data::_ins = nullptr;


Game_data * Game_data::getInstance()
{
	if (_ins == nullptr)
		_ins = new Game_data();








	return _ins;
}

Game_data::Game_data()
{

}


Game_data::~Game_data()
{



}


void Game_data::save_star_nums(int bigIdx, int smallIdx, int starNum)
{
	char str[32] = { 0 };
	sprintf(str, "starNum_%d_%d", bigIdx, smallIdx);
	UserDefault::getInstance()->setIntegerForKey(str, starNum);



}


int Game_data::get_starnum(int bigIdx, int smallIdx)
{
	char str[32] = { 0 };
	sprintf(str, "starNum_%d_%d", bigIdx, smallIdx);
	return UserDefault::getInstance()->getIntegerForKey(str, 0);

	

}


void Game_data::set_passvount(int bigIdx,int passCount)
{
	char str[32] = { 0 };
	sprintf(str, "isPass_%d",bigIdx);

	UserDefault::getInstance()->setIntegerForKey(str, passCount);

}






int  Game_data::getpass_count(int bigIdx)
{
	char str[32] = { 0 };
	sprintf(str, "isPass_%d");
	return UserDefault::getInstance()->getIntegerForKey(str, 1);

}


