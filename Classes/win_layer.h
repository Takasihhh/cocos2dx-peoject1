#ifndef __WIN_LAYER__
#define __WIN_LAYER__


#include <stdio.h>
#include"cocos2d.h"
using namespace cocos2d;


class win_layer :public Layer
{


	private:
		Menu* m_menu;
		Size winSize;
		int m_xingxingNum;
		Director* pDirector;
	public:
		static win_layer* create(int xingxingnum);
		bool InitWinLayer(int xingxingnum);

		virtual bool onTouchBegan(Touch *pTouch, Event *pEvent) override;

	public:
		void Back(Ref* obj);
		void Replay(Ref* obj);
		void Next(Ref* obj);

};





#endif