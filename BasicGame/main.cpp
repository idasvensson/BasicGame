//
//  main.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//
// Möjligt för tillämpare att lägga till bind-funktioner för knapptryck, t.ex.
// LazyFoo: Timing, Collision Detection, Animation
//
// Ändringar:
// - Skapade en default tillämpning av .tick hos Sprite, som inluppen krävde.
// - Skapade Image-klassen efter beskrivningen av inluppen
//

#include "SDL/SDL.h"
#include "GameEngine.h"
#include "Globals.h"
#include "PlayerSprite.h"
#include "BlockSprite.h"
#include "Image.h"
#include <iostream>
using namespace std;
using namespace basicgame;

void quit(string dummy){
    exit(0);
}

int main(int argc, char**argv)
{
    sys.init();
    
    // Frame fram;
    GameEngine engineObject(30);
    
    PlayerSprite* p = PlayerSprite::getInstance(300, 200, 1, 1, "/Users/idasvensson/Desktop/images/boll.bmp");
    BlockSprite* b = BlockSprite::getInstance(400, 100, 0, 0, "/Users/idasvensson/Desktop/images/arr-right.bmp");
    
    engineObject.add(p);
    engineObject.add(b);
    
    // Test av Image med kopiering, tilldelning och refcount
    Image A( "/Users/idasvensson/Desktop/images/boll.bmp", false );
    Image B( "/Users/idasvensson/Desktop/images/boll.bmp", false );
    Image C(A);
    Image D = A;
    
    engineObject.run();
    
    return 0;
}
