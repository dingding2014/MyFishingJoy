#include "FishLayer.h"
USING_NS_CC;
bool FishLayer::init()
{
	if (!Layer::init()){
		return false;
	}
	//�����������СΪ10,�����ʮ����
    int capacity = 10;
	_fishes = __Array::createWithCapacity(capacity);
	CC_SAFE_RETAIN(_fishes);
    for (int i = 0; i < capacity; i++){		
		int type = CCRANDOM_0_1() * 2;
		Fish* fish = Fish::create((FishType)type);
		_fishes->addObject(fish);
	}
	this->schedule(schedule_selector(FishLayer::addFish), 3.0);
	return true;
}
void FishLayer::addFish(float dt)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	int countToAdd = CCRANDOM_0_1() * 10 + 1;
	int countHasAdded = 0;
	CCObject* iterator;
	CCARRAY_FOREACH(_fishes, iterator){
		Fish* fish = (Fish*)iterator;
		if (fish->isRunning() == false){
			this->addChild(fish);
			//todo ����Ӧ����Fish����ʱ���������
			int randomX = CCRANDOM_0_1() * visibleSize.width;
			int randomY = CCRANDOM_0_1() * visibleSize.height;
			fish->setPosition(Vec2(origin.x+randomX, origin.y+randomY));
			countHasAdded++;
			if (countToAdd == countHasAdded){
				break;
			}
		}
	}
}
FishLayer::~FishLayer()
{
	CC_SAFE_RELEASE(_fishes);
}