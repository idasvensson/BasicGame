//
//  Globals.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "Globals.h"
#include "SDL/SDL.h"

namespace basicgame {
    
    void Globals::init()
    {
        SDL_Init(SDL_INIT_EVERYTHING); // Innan main anropas
        screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    }
    
    Globals::~Globals()
    {
        SDL_Quit(); // Efter att programmet avslutats
    }
    
    Globals sys;
    
} // namespace basicgame
