#include "BackgroundLayer.h"
#include "StaticData.h"
USING_NS_CC;
bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sprite = Sprite::createWithSpriteFrameName(STATIC_DATA_STRING("background"));
	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	/*
	if (CCLayer::init()){
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		CCSprite* background = CCSprite::createWithSpriteFrameName(STATIC_DATA_STRING("background"));
		background->setPosition(CCPointMake(winSize.width*0.5, winSize.height*0.5));
		this->addChild(background);
		return true;
	}
	return false;
	*/
}