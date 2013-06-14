cocos2d-xTestWorkSpace
======================

Test Work Space for my cocos2d-x projects

Tests:

MaluchiTest
-----------
* Use the TestCpp project and add this directory to the "Classes" directory
* Add the following stuff
 * in `tests.h` add one item to the first enum, and a title to `g_aTestNames` (they must have the same "index" for things to work properly)
 * in `controller.cpp` add the case for the item added in `tests.h`'s enum:

            case MALUCHI_TEST:
              pScene = new MaluchiTest(); break;     
