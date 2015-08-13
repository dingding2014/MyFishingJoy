#include "Fish.h"
#include "StaticData.h"
USING_NS_CC;
enum{
	k_Action_Animate = 0,
};
Fish* Fish::create(FishType type)
{
	Fish* fish = new Fish();
	fish->init(type);
	fish->autorelease();
	return fish;
}
bool Fish::init(FishType type)
{
	_type = type;
	__String* animationName = __String::createWithFormat(STATIC_DATA_STRING("fish_animation"), _type);
	//从动画缓存中根据名称fish_animation_0,fish_animation_1获取动画
	Animation* fishAnimation = AnimationCache::getInstance()->animationByName(animationName->getCString());
	Animate* fishAnimate = Animate::create(fishAnimation);
	fishAnimate->setTag(k_Action_Animate);
	_fishSprite = Sprite::create();
	this->addChild(_fishSprite);
	_fishSprite->runAction(RepeatForever::create(fishAnimate));
	return true;
}