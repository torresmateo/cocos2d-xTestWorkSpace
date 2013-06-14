//
//  MaluchiTest.h
//  TestCpp
//
//  Created by Mateo Torres on 6/13/13.
//
//

#ifndef __TestCpp__MaluchiTest__



#define __TestCpp__MaluchiTest__

#include "../testBasic.h"

class MaluchiTest : public TestScene
{
public:
    virtual void runThisTest();
};

class MaluchiMainLayer : public CCLayer
{
public:
    MaluchiMainLayer();
    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
    virtual void addNewSpriteAtPosition(CCPoint pos);

};


#endif /* defined(__TestCpp__MaluchiTest__) */
