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
    
    BlockSprite::BlockSprite(int x, int y) :
    Sprite(x, y)
    {
        rect.x = x;
        rect.y = y;
        img = SDL_LoadBMP("/Users/idasvensson/Desktop/images/boll.bmp");
        
        // Addrea transparens till bildens vita pixlar
        Uint32 white = SDL_MapRGB(img->format, 255, 255, 255);
        Uint32 pixel = pixel = *((Uint32*)img->pixels);
        SDL_SetColorKey(img, SDL_SRCCOLORKEY|SDL_RLEACCEL, white);
    }
    
    BlockSprite* BlockSprite::getInstance(int x, int y)
    {
        return new BlockSprite(x, y);
    }
    
    void BlockSprite::draw()
    {
        // Rita ut bilden på skärmytan
        SDL_BlitSurface(img, NULL, sys.screen, &rect);
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
		SDL_FreeSurface(img);
	}
    
}