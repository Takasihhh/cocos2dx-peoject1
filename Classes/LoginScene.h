#ifndef __LOGINSCENE_SCENE_H__
#define __LOGINSCENE_SCENE_H__

#include "cocos2d.h"

class LoginScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	//Ìí¼Ó²ã
	void addLayer();
	//ÒÆ³ý²ã
	void removeLayer();
};

#endif // __LOGINSCENE_SCENE_H__
