#ifndef __BIGLEVEL_LAYER__
#define __BIGLEVEL_LAYER__
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"  //���밴ť��guiͷ�ļ�
#include"cocos2d.h"
using namespace cocos2d;
using namespace cocos2d::ui;

class BigLevelLayer:public cocos2d::Layer
{
public:
	
	virtual bool init();
	CREATE_FUNC(BigLevelLayer);


	void change_choicelevel_scene(Ref *ref, Widget::TouchEventType type);

	ActionInterval * create_rabbit_ani();
private:
	 
};







#endif