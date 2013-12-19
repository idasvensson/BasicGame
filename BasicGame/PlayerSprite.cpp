//
//  PlayerSprite.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "SDL/SDL.h"
#include "Globals.h"
#include "PlayerSprite.h"
#include <iostream>
#include <vector>
using namespace std;

namespace basicgame{

    PlayerSprite::PlayerSprite(int x, int y) :
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
    
    PlayerSprite* PlayerSprite::getInstance(int x, int y)
    {
        return new PlayerSprite(x, y);
    }
    
    void PlayerSprite::draw()
    {
        // Rita ut bilden på skärmytan
        SDL_BlitSurface(img, NULL, sys.screen, &rect);
    }
    
    void PlayerSprite::keyDown(int key) {
        // cout << "Key down: " << key << endl;
        switch(key) {
        
            case SDLK_UP:
                cout << "Uppåt" << endl;
                break;
            case SDLK_DOWN:
                cout << "Neråt" << endl;
                break;
            case SDLK_RIGHT:
                rect.x +=5;
                img = SDL_LoadBMP("/Users/idasvensson/Desktop/images/arr-right.bmp");
                //this->xpos +=5;
                break;
            case SDLK_LEFT:
                rect.x -=5;
                img = SDL_LoadBMP("/Users/idasvensson/Desktop/images/arr-left.bmp");
                //this->xpos -=5;
                break;
            case SDLK_SPACE:
                // Hoppa?
                break;
                
        } // switch
    }
    
    void PlayerSprite::tick(std::vector<Sprite*> sprites)
    {
        
    }

    PlayerSprite::~PlayerSprite() {
		SDL_FreeSurface(img);
		SDL_FreeSurface(rightImg);
		SDL_FreeSurface(leftImg);
	}
    
}