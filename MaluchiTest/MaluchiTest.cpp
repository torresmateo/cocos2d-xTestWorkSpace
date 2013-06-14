//
//  MaluchiTest.cpp
//  TestCpp
//
//  Created by Mateo Torres on 6/13/13.
//
//

#include "MaluchiTest.h"
#include "../testResource.h"

enum {
    kTagSprite = 1,
    
};

void MaluchiTest::runThisTest()
{
    CCLayer* pLayer = new MaluchiMainLayer();
    pLayer->autorelease();
    
    addChild(pLayer);
    CCDirector::sharedDirector()->replaceScene(this);
}


MaluchiMainLayer::MaluchiMainLayer()
{
    setTouchEnabled(true);
    
    //se crea un Sprite cualquiera
    CCSprite* sprite = CCSprite::create("Images/grossini_dance_09.png");
    
    //se crea un fondo negro
    CCLayer* layer = CCLayerColor::create(ccc4(0, 0, 0, 255));
    
    //se agregan a la escena el fondo y el sprite
    addChild(layer, -1);
    addChild(sprite, 0, kTagSprite);
    //
    sprite->setPosition(ccp(20, 150));
    
    sprite->runAction(CCJumpTo::create(4, ccp(300, 48), 100, 4));
                      
                      
}

//basado en PerformanceSpriteTest
void actions(CCSprite* pSprite, CCPoint pos)
{
    //se creara el sprite en la posición en la que se hizo tap
    pSprite->setPosition(pos);
    
    
    //ROTACIÓN
    
    //se crea un periodo random para la rotación del sprite
    float period = 0.5f + (rand() % 1000) / 500.0f;
    //se define una posible rotacion para ese sprite
    CCActionInterval* rotation = CCRotateBy::create(period, 360.0f * CCRANDOM_0_1());
    //se crea una secuencia infinita de "rebotes" de rotación
    CCAction* permanentRotation = CCRepeatForever::create(CCSequence::create(rotation,rotation->reverse(),NULL));
    pSprite->runAction(permanentRotation);
    
    //ESCALAMIENTO
    
    //se define un periodo random para el escalamiento del sprite
    float growDuration = 0.5f + (rand() % 1000) / 500.0f;
    //crecimiento (crece 50%)
    CCActionInterval* grow = CCScaleBy::create(growDuration, 0.5f, 0.5f);
    //se crea una secuencia infinita de "palpitación" de escalamiento
    CCAction* permanentScaleLoop = CCRepeatForever::create(CCSequence::create(grow, grow->reverse(),NULL));
    pSprite->runAction(permanentScaleLoop);
    
    
}

//copiado del ChipmunkTest
void MaluchiMainLayer::addNewSpriteAtPosition(CCPoint pos)
{
    CCSprite *sprite = CCSprite::create("Images/grossini_dance_09.png");
    actions(sprite, pos);
    addChild(sprite);
}


void MaluchiMainLayer::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    //Add a new body/atlas sprite at the touched location
    CCSetIterator it;
    CCTouch* touch;
    
    for( it = touches->begin(); it != touches->end(); it++)
    {
        touch = (CCTouch*)(*it);
        
        if(!touch)
            break;
        
        CCPoint location = touch->getLocation();
        
        addNewSpriteAtPosition( location );
    }
}


