#ifndef  __LOADING_LAYER__
#define __LOADING_LAYER__
#include"cocos2d.h"
class LoadingLayer :public cocos2d::Layer
{
public:

	//≥ı ºªØ
	virtual bool init();
	//create
	CREATE_FUNC(LoadingLayer);

	//«–ªª≥°æ∞
    void change_to_LoginScene(float time);

};



#endif