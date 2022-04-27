
#include"LoadingScene.h"
#include"Loadinglayer.h"
LoadingScene::Scene* LoadingScene::createScene()
{


//添加场景
	auto pScene = Scene::create();
	//添加层
	auto layer = LoadingLayer::create();
	//层添加到场景上
	pScene->addChild(layer);

	//返回场景
	return pScene;
}
