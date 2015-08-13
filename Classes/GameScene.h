//#ifndef __Game_Scene_H__
//#define __Game_Scene_H__
#ifndef GameScene_H
#define GameScene_H

#include "cocos2d.h"
#include "BackgroundLayer.h"
#include "FishLayer.h"

typedef enum{
	k_Operate_Pause = 0,
	k_Operate_Resume
}OperateFlag;

class GameScene : public cocos2d::Layer
{
public:
	CREATE_FUNC(GameScene);
	static cocos2d::Scene* createScene();
	virtual bool init();

protected:
	BackgroundLayer* _backgroundLayer;
	FishLayer* _fishLayer;

	//暂停或恢复场景内运行的所有节点
	void operateAllSchedulerAndActions(cocos2d::CCNode* node, OperateFlag flag);

	//todo 预载入资源，实现StartScene后将其删除
	void preloadResources();
};

#endif /* defined(__FishingJoy__GameScene__) */