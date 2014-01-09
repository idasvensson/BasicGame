//
//  MovingSprite.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2014-01-09.
//  Copyright (c) 2014 Ida Svensson. All rights reserved.
//

#include "SDL/SDL.h"
#include "Globals.h"
#include "MovingSprite.h"
#include <iostream>
#include <vector>
using namespace std;

namespace basicgame{
    
    MovingSprite::MovingSprite(int x, int y, int xVel, int yVel, string filename, bool transparent) :
    Sprite(x, y, filename, transparent)
    {
        // Initialize offsets
        rect.x = x;
        rect.y = y;
    }
    
    MovingSprite* MovingSprite::getInstance(int x, int y, int xVel, int yVel, string filename, bool transparent = true)
    {
        return new MovingSprite(x, y, xVel, yVel, filename, transparent);
    }
    
    void MovingSprite::draw()
    {
        
    }
    
    void MovingSprite::tick(std::vector<Sprite*> sprites) // Använda rect.x och rect.y eller x och y?
    {
        
    }
    
    MovingSprite::~MovingSprite() {
		
	}
    
}
