#include "game_map.h"

//私有变量
Size game_map::m_tTileSize = Size(1120, 700);
Size game_map::m_tMapSize = Size(15, 9);

//game_map方法实现

game_map* game_map::create(const char *tmxFile)
{
	game_map *pRet = new game_map();
	if (pRet->initWithTMXFile(tmxFile))
	{
		pRet->autorelease();
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return NULL;


}


ValueMap game_map::getobjForName(const char* groupName, const char *objectName)
{
	CCAssert(groupName != NULL && strlen(groupName) > 0, "Invaild group name!");//判空

		std::string sGroupName = groupName;
		if (TMXTiledMap::getObjectGroups().size()>0)
		{
			TMXObjectGroup* objectGroup = this->getObjectGroup(sGroupName);
			for (auto p : TMXTiledMap::getObjectGroups())
			{
				if (objectGroup && objectGroup->getGroupName() == sGroupName)
				{
					ValueMap va = getDictionary(objectGroup, objectName);
					return va;
				}
			}
		}
		return ValueMap();
}

Point game_map::getobjectPositionForName(const char* groupName, const char *objectName)
{
	CCAssert(groupName != NULL && strlen(groupName) > 0, "Invaild group name!");//判空

	ValueMap pDict = getobjForName(groupName, objectName);

	float x = pDict["x"].asFloat();
	float y = pDict["y"].asFloat();


	CCLOG("x%lf", x);
	CCLOG("y%lf", y);

	return Vec2(x, y);

}



//私有方法
ValueMap game_map::getDictionary(TMXObjectGroup* group, const char * objectName)
{

	ValueMap obj = group->getObject(objectName);

	return obj;
}



__String game_map::getCustonStr(const char* groupName, const char* objectName, const char * property)
{
	CCAssert(groupName != NULL && strlen(groupName) > 0, "Invaild group name!");//判空
	ValueMap pDict = getobjForName(groupName, objectName);

	return pDict[property].asString();

}



Point game_map::convertToMapTdx(const Point&pos)
{
	int x = (int)pos.x / 70;
	int y = 9-(int)pos.y / 70;

	return Point(x, y);


}


Point game_map::convertToUIPos(const Point& mapIdx)
{
	float x = (mapIdx.x) * 70;
	float y = (9 - mapIdx.y) * 70;
	return Point(x, y);
	return Point(mapIdx.x * m_tTileSize.width + m_tTileSize.width / 2 + this->getPositionX(), (m_tMapSize.height - 1 - mapIdx.y)* m_tTileSize.height + m_tTileSize.height / 2 + this->getPositionY());

}


Point game_map::getTargetPos(const char*layerName, const Point& curPos, const CHECKDIR& dir)
{
	TMXLayer* layer = this->layerNamed(layerName);

	if (layer)
	{
		Point curIdx = this->convertToMapTdx(curPos);
		Point dirVec;
		switch (dir)
		{
		case CHECKDIR_UP:
			dirVec = Vec2(0, -1);
			break;
		case CHECKDIR_DOWN:
			dirVec = Vec2(0, 1);
			break;
		case CHECKDIR_LEFT:	
			dirVec = Vec2(-1, 0);
			break;
		case CHECKDIR_RIGHT:
			dirVec = Vec2(1, 0);
			break;
		default:
			break;
		}
		while (true)
		{
			curIdx += dirVec;
			if (curIdx.x < 0 || curIdx.x >= m_tMapSize.width || curIdx.y < 0 || curIdx.y >= m_tMapSize.height)
			{
				return convertToUIPos(curIdx - dirVec);

			}
			else if (layer->tileGIDAt(curIdx) != 0)
			{
				return convertToUIPos(curIdx - dirVec);
			}
		}
	}


	return curPos;

}

