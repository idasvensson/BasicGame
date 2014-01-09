//
//  BlockSprite.h
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-16.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__BlockSprite__
#define __BasicGame__BlockSprite__

#include "SDL/SDL.h"
#include "Sprite.h"
#include <vector>

namespace basicgame {
    
    class BlockSprite : public Sprite {
        
    public:
        static BlockSprite* getInstance(int x, int y, std::string filename, bool transparent = true);
        void draw();
        void animationStart();
        void animationStop();
        virtual void tick(std::vector<Sprite*> sprites);
        ~BlockSprite();
        int x, y;
    protected:
        BlockSprite(int x, int y, std::string filename, bool transparent);
    private:
        //SDL_Surface* img;
        // bool isMoving;
        
    };
    
}


#endif /* defined(__BasicGame__BlockSprite__) */
