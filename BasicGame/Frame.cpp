//
//  Frame.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "Frame.h"
#include "SDL/SDL.h"
#include "Globals.h"

namespace basicgame {

    void Frame::add(Sprite* ny){
        sprites.push_back(ny);
    }
    
    void Frame::forAll( void(Sprite::*mpek)(int, int), int x, int y ) {
        for(int i = 0; i < sprites.size(); i++)
            (sprites[i]->*mpek)(x, y);
    }
    
    void Frame::run() {
        for (int i = 0; i < sprites.size(); i++)
            sprites[i]->draw();
        SDL_Flip(sys.screen);
        
        SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL);
        
        // Händelseloop
        bool running = true;
        while(running) {
        
            SDL_Event ev;
            while (SDL_PollEvent(&ev)) {
            
                switch (ev.type) {
                
                    case SDL_QUIT:
                        running = false;
                        break;
                        
                    case SDL_KEYDOWN:
                        for(int i=0; i<sprites.size();i++)
                            sprites[i]->keyDown(ev.key.keysym.sym);
                        break;
                
                } // switch
                
            } // while SDL_PollEvent
            
            Uint32 white = SDL_MapRGB(sys.screen->format, 255, 255, 255);
            SDL_FillRect(sys.screen, NULL, white); // Fyll hela skärmen vit
            
            for(int i=0; i<sprites.size(); i++)
                sprites[i]->draw();
            
            SDL_Flip(sys.screen);
            
        } // while running
    }
    
    Frame::~Frame() {
    }
    
}