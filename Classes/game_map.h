#ifndef __GAME_MAP__
#define __GAME_MAP__

#include"cocos2d.h"
using namespace cocos2d;


enum CHECKDIR
{

	CHECKDIR_UP,
	CHECKDIR_DOWN,
	CHECKDIR_LEFT,
	CHECKDIR_RIGHT
};


class game_map :public TMXTiledMap
{
public:
	static game_map* create(const char *tmxFile);
	ValueMap getobjForName(const char* groupName, const char *objectName);
	Point getobjectPositionForName(const char* groupName, const char *objectName);
	__String getCustonStr(const char* groupName, const char* objectName, const char * property);
	Point getTargetPos(const char*layerName, const Point& curPos, const CHECKDIR& dir);


	static Size m_tTileSize;
	static Size m_tMapSize;

private:


	ValueMap getDictionary(TMXObjectGroup* group, const char * objectName);
	Point convertToMapTdx(const Point&pos);
	Point convertToUIPos(const Point& mapIdx);


};







#endif

