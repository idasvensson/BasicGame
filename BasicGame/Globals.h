//
//  Globals.h
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__Globals__
#define __BasicGame__Globals__

#include "SDL/SDL.h"
#include "SDL_ttf/SDL_ttf.h"

namespace basicgame{
    
    struct Globals
    {
        void init(); // I stället för konstruktor på Mac
        ~Globals();
        SDL_Surface* screen;
        const int SCREEN_WIDTH = 800;
        const int SCREEN_HEIGHT = 600;
    };
    
    extern Globals sys;
    
} // namespace basicgame

#endif /* defined(__BasicGame__Globals__) */
