#pragma once
#pragma execution_charater_set("utf-8")

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class Gamescene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	//��Ӳ�
	void addLayer();
	//�Ƴ���
	void removeLayer();
};

#endif // __LOGINSCENE_SCENE_H__
