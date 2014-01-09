//
//  MovingSprite.h
//  BasicGame
//
//  Created by Ida Svensson on 2014-01-09.
//  Copyright (c) 2014 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__MovingSprite__
#define __BasicGame__MovingSprite__

#include "SDL/SDL.h"
#include "Sprite.h"
#include <vector>
#include <string>

// Flytta getInstance till Sprite? tick?

namespace basicgame {
    
    class MovingSprite : public Sprite {
        
    public:
        static MovingSprite* getInstance(int x, int y, int xVel, int yVel, std::string filename, bool transparent);
        virtual void draw();
        ~MovingSprite();
        virtual void tick(std::vector<Sprite*> sprites);
    protected:
        MovingSprite(int x, int y, int xVel, int yVel, std::string filename, bool transparent);
    private:
        
    };
    
}

#endif /* defined(__BasicGame__MovingSprite__) */
