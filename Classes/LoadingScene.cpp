
#include"LoadingScene.h"
#include"Loadinglayer.h"
LoadingScene::Scene* LoadingScene::createScene()
{


//��ӳ���
	auto pScene = Scene::create();
	//��Ӳ�
	auto layer = LoadingLayer::create();
	//����ӵ�������
	pScene->addChild(layer);

	//���س���
	return pScene;
}
