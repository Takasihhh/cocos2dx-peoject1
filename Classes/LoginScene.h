#ifndef __LOGINSCENE_SCENE_H__
#define __LOGINSCENE_SCENE_H__

#include "cocos2d.h"

class LoginScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	//��Ӳ�
	void addLayer();
	//�Ƴ���
	void removeLayer();
};

#endif // __LOGINSCENE_SCENE_H__
