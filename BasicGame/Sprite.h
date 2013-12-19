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

namespace basicgame {

    class Sprite {
    
    public:
        virtual void draw() = 0;
        virtual void tick(std::vector<Sprite*> sprites);
        Rectangle getRect();
        virtual ~Sprite();
        virtual void keyDown(int key);
        // virutal void getSpeed();
        // virtual void getPosition();
        // virtual void setSpeed();
        // virtual void setPosition(int x, int y);
    protected:
        Sprite(int x, int y);
        Rectangle rect;
    private:
        Sprite(const Sprite&); // Förbjud tilldelningar med copy-konstruktorn
        const Sprite& operator=(const Sprite&); // Förbjud automatisk tilldening med tilldelningsoperator
        // int speed;
        // iny position;
    };

} // namespace basicgame

#endif /* defined(__BasicGame__Sprite__) */
