#ifndef  __LOADING_LAYER__
#define __LOADING_LAYER__
#include"cocos2d.h"
class LoadingLayer :public cocos2d::Layer
{
public:

	//��ʼ��
	virtual bool init();
	//create
	CREATE_FUNC(LoadingLayer);

	//�л�����
    void change_to_LoginScene(float time);

};



#endif