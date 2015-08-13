#include "GameScene.h"
#include "StaticData.h"
#include "FishingJoyData.h"
#include <cstdio>
USING_NS_CC;
//todo Ԥ������Դ��ʵ��StartScene����ɾ��
void GameScene::preloadResources()
{
	//���ؾ���֡����
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("fishingjoy_resource.plist");
	
	int frameCount = STATIC_DATA_INT("fish_frame_count");
	for (int type = k_Fish_Type_Red; type < k_Fish_Type_Count; type++) {
		Animation* fishAnimation = Animation::create();
		for (int i = 0; i < frameCount; i++){
			__String* filename = __String::createWithFormat(STATIC_DATA_STRING("fish_frame_name_format"), type, i);
			SpriteFrame* spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(filename->getCString());
			fishAnimation->addSpriteFrame(spriteFrame);//һ֡һ֡���붯��
		}
		//��������֮֡��Ĳ���ʱ��
		fishAnimation->setDelayPerUnit(STATIC_DATA_FLOAT("fish_frame_delay"));
		__String* animationName = __String::createWithFormat(STATIC_DATA_STRING("fish_animation"), type);
		CCAnimationCache::sharedAnimationCache()->addAnimation(fishAnimation, animationName->getCString());
	}
}
Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}
	//������Դ,��Ҫ�����֡����
	preloadResources();

	//���ر�����
	_backgroundLayer = BackgroundLayer::create();
	this->addChild(_backgroundLayer);

	//�������
	_fishLayer = FishLayer::create();
	this->addChild(_fishLayer);
	
	return true;
}