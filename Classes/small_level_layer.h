#ifndef __SMALL_LEVEL_LAYER__
#define __SMALL_LEVEL_LAYER__


#include"cocostudio\CocoStudio.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"  //引入按钮的gui头文件
using namespace cocos2d::ui;
using namespace cocos2d;
USING_NS_CC;


class small_level_layer: public cocos2d::Layer
{
public:

	virtual bool init();

	CREATE_FUNC(small_level_layer);

	void change_choicelevel_scene(Ref *ref, Widget::TouchEventType type);

private:

};






#endif