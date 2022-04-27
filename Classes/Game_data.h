#ifndef __GAME_DATA__
#define __GAME_DATA__

#include"cocos2d.h"
using namespace cocos2d;
class Game_data
{
public:

	~Game_data();

	static  Game_data* getInstance();


	static int s_iCurBigLevel;
	static int s_iCurSmallLevel;

	static void save_star_nums(int bigIdx, int smallIdx, int starNum);
	static int get_starnum(int bigIdx, int smallIdx);
	static int getpass_count(int bigIdx);
	static void set_passvount(int bigIdx, int passCount);
private:
	Game_data();

static  Game_data* _ins;

};



#endif