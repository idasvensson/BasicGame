//
//  Sprite.h
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__Sprite__
#define __BasicGame__Sprite__

#include "Rectangle.h"
#include <vector>
#include "Image.h"
#include <string>

namespace basicgame {

    class Sprite {
    
    public:
        virtual void draw() = 0;
        virtual void tick(std::vector<Sprite*> sprites);
        Rectangle getRect();
        virtual ~Sprite();
        virtual void keyDown(int key);
        virtual void keyUp(int key);
        
        // virutal int getSpeed();
        // virtual int getPosition();
        // virtual void setSpeed(int xVel, int yVel);
        // virtual void setPosition(int x, int y);
        virtual void setImage(std::string filename, bool transparent);
    protected:
        Sprite(int x, int y, std::string filename, bool transparent);
        Rectangle rect;
        Image image;
        void setXVel(int newVel);
        void setYVel(int newVel);
        int getXVel();
        int getYVel();
    private:
        int x, y;
        int xVel;
        int yVel;
        Sprite(const Sprite&); // Förbjud tilldelningar med copy-konstruktorn
        const Sprite& operator=(const Sprite&); // Förbjud automatisk tilldening med tilldelningsoperator
    };

} // namespace basicgame

#endif /* defined(__BasicGame__Sprite__) */
