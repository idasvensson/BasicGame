//
//  BlockSprite.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-16.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "BlockSprite.h"
#include "SDL/SDL.h"
#include "Globals.h"
#include <iostream>
#include <vector>
using namespace std;

namespace basicgame{
    
    BlockSprite::BlockSprite(int x, int y, int xVel, int yVel, string filename, bool transparent) :
    Sprite(x, y, 0, 0, filename, transparent)
    {
        rect.x = x;
        rect.y = y;
        // img = SDL_LoadBMP("/Users/idasvensson/Desktop/images/boll.bmp");
    }
    
    BlockSprite* BlockSprite::getInstance(int x, int y, int xVel, int yVel, string filename, bool transparent)
    {
        return new BlockSprite(x, y, xVel, yVel, filename, transparent);
    }
    
    void BlockSprite::draw()
    {
        // Rita ut bilden på skärmytan
        // SDL_BlitSurface(img, NULL, sys.screen, &rect);
    }
    
    void BlockSprite::animationStart()
    {
        
    }
    
    void BlockSprite::animationStop()
    {
        
    }
    
    void BlockSprite::tick(vector<Sprite*> sprites)
    {
        
        
        if (sys.screen->w != (rect.x - 80))
            rect.x += 5;
    }
    
    BlockSprite::~BlockSprite() {
		//SDL_FreeSurface(img);
	}
    
}