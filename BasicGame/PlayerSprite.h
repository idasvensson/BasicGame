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
#include "MovingSprite.h"
#include <vector>
#include <string>

namespace basicgame {

    class PlayerSprite : public MovingSprite {
    
    public:
        static PlayerSprite* getInstance(int x, int y, int xVel, int yVel, std::string filename, bool transparent = true);
        void draw();
        void keyDown(int key);
        void keyUp(int key);
        ~PlayerSprite();
        int x, y; // rect?
        virtual void tick(std::vector<Sprite*> sprites);
    protected:
        PlayerSprite(int x, int y, int xVel, int yVel, std::string filename, bool transparent);
    private:
        //SDL_Surface* img;
        //SDL_Surface* rightImg;
        //SDL_Surface* leftImg;
        
    };

}

#endif /* defined(__BasicGame__PlayerSprite__) */
