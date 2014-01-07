//
//  GameEngine.h
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-16.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__GameEngine__
#define __BasicGame__GameEngine__

#include "Sprite.h"
#include <vector>
#include "Timer.h"

namespace basicgame {
    
    class GameEngine {
    public:
        //medlemsfunktioner
        typedef void (*FuncPointer)(std::string);
        void add(Sprite* ny);
        void run();
        bool bindKey(int sdlKeyValue, FuncPointer fp);
        void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination);
        
        //konstruktorer
        ~GameEngine();
        GameEngine(const unsigned short int MAX_FRAME_RATE);
    private:
        // Medlemmar fˆr timing och frame rate-regulering
		Timer timer;
		int frameCounter = 0;
        
        std::vector<Sprite*> sprites; // En vector av Sprite-objekt-pekare
        void forAll( void(Sprite::*mpek)(int, int), int x, int y);
        const unsigned short int MAX_FRAME_RATE;
        FuncPointer fu;
        // Ovan: (medlemspekare till en funktion i klassen Sprite -vilken tar 2 int som args, int 1, int 2)
    };
    
}

#endif /* defined(__BasicGame__GameEngine__) */
