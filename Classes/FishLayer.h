#ifndef __FishingJoy__FishLayer__
#define __FishingJoy__FishLayer__
#include "cocos2d.h"
#include "Fish.h"
class FishLayer : public cocos2d::Layer
{
public:
	CREATE_FUNC(FishLayer);
	virtual bool init();
	CC_SYNTHESIZE_READONLY(cocos2d::__Array*, _fishes, Fishes);
	virtual ~FishLayer();
protected:
	void addFish(float dt);
};
#endif