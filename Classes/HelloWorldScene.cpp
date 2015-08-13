#include "HelloWorldScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));
	
    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
	
    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    //auto sprite = Sprite::create("HelloWorld.png");
	//auto sprite = Sprite::create("D:\\Myfish\\MyFishGame\\Resources\\background.png");
	auto sprite = Sprite::create("background.png");
    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
	
	//sprite->runAction(FlipX::create(true));
	//sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    //sprite->runAction(Blink::create(3,5)); 闪烁动作
	CCSprite* title = CCSprite::create("title.png");
	title->setPosition(Vec2(visibleSize.width*0.5, visibleSize.width*0.45));
	this->addChild(title);

	
	//添加开始游戏菜单项	
	auto item = MenuItemFont::create("Start Game", CC_CALLBACK_1(HelloWorld::onPushSceneTran, this));
	
	auto Startmenu = Menu::create(item,NULL);
	
	Startmenu->alignItemsVertically();
	//addChild(Startmenu);
	this->addChild(Startmenu,5);
    return true;
}

void HelloWorld::onPushSceneTran(Ref* sender)
{
	auto scene1 = GameScene::createScene();
	Director::getInstance()->pushScene(CCTransitionFadeDown::create(1.0f, scene1));
	//scene1->release();
	/*
	CCScene* scene = CCTransitionFadeDown::create(1.0f, GameScene::createScene());
	CCDirector::sharedDirector()->replaceScene(scene);*/
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
