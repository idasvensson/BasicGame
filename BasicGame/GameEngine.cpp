//
//  GameEngine.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-16.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "stdafx.h"
#include "GameEngine.h"
#include "SDL/SDL.h"
#include "Globals.h"
#include <vector>
#include <iostream>

namespace basicgame {
    
    GameEngine::GameEngine(const unsigned short int MAX_FRAME_RATE) : MAX_FRAME_RATE(MAX_FRAME_RATE){}
    
    void GameEngine::add(Sprite* ny){
        sprites.push_back(ny);
    }
    
    void GameEngine::forAll( void(Sprite::*mpek)(int, int), int x, int y ) {
        for(int i = 0; i < sprites.size(); i++)
            (sprites[i]->*mpek)(x, y);
    }
    
    void GameEngine::run() {
        for (int i = 0; i < sprites.size(); i++)
            sprites[i]->draw();
        SDL_Flip(sys.screen);
        
        // SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL);
        
        // Händelseloop
        bool quit = false;
        SDL_Event event;
        while(!quit) {
            
            // Starta timern
			timer.start();
            
            while (SDL_PollEvent(&event)) {
                
                switch (event.type) {
                        
                    case SDL_QUIT:
                        quit = true;
                        break;
                        
                    case SDL_KEYDOWN:
                        for(int i=0; i<sprites.size();i++)
                            sprites[i]->keyDown(event.key.keysym.sym);
                        break;
                        
                    case SDL_KEYUP:
                        
						for (int i = 0; i<sprites.size(); i++)
							sprites[i]->keyUp(event.key.keysym.sym);
						break;
                        
                } // switch
                
            } // while SDL_PollEvent
            
            Uint32 white = SDL_MapRGB(sys.screen->format, 255, 255, 255);
            SDL_FillRect(sys.screen, NULL, white); // Fyll hela skärmen vit
            
            for(int i=0; i<sprites.size(); i++)
            {
                sprites[i]->tick(sprites);
                sprites[i]->draw();
                
            }
                
            SDL_Flip(sys.screen);
            
            frameCounter++;
            
			// Om vår timer har gått mindre än tiden det ska ta för varje frame
			if ((timer.getTicks() < 1000 / MAX_FRAME_RATE))
			{
				// Då väntar vi den tiden som återstår
				SDL_Delay((1000 / MAX_FRAME_RATE) - timer.getTicks());
			}
            
        } // while running
    }
    
    bool GameEngine::bindKey(int sdlKeyValue, FuncPointer fp)
    {
        return true;
    }
    
    GameEngine::~GameEngine() {
    }
    
}