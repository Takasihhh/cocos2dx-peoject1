#ifndef __POINT_BOARD__
#define __POINT_BOARD__

#include "cocos2d.h"
#include "ui/CocosGUI.h"  //引入按钮的gui头文件

#include "BigLevelScene.h"
using namespace cocos2d::ui;
using namespace cocos2d;
class point_board :public Sprite  
{
public:
	static point_board* create(const std::string& filename);

	virtual  bool init_ui();
	virtual bool init_cout();
	virtual bool  init_btn();


	 Size visibleSize = Director::getInstance()->getVisibleSize();

private:
	

};









#endif