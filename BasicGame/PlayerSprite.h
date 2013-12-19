//
//  PlayerSprite.h
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__PlayerSprite__
#define __BasicGame__PlayerSprite__

#include "SDL/SDL.h"
#include "Sprite.h"
#include <vector>

namespace basicgame {

    class PlayerSprite : public Sprite {
    
    public:
        static PlayerSprite* getInstance(int x, int y);
        void draw();
        void keyDown(int key);
        ~PlayerSprite();
        int x, y;
        virtual void tick(std::vector<Sprite*> sprites);
    protected:
        PlayerSprite(int x, int y);
    private:
        SDL_Surface* img;
        SDL_Surface* rightImg;
        SDL_Surface* leftImg;
        // bool isMoving;
        
    };

}

#endif /* defined(__BasicGame__PlayerSprite__) */
