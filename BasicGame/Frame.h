//
//  Frame.h
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__Frame__
#define __BasicGame__Frame__

#include "Sprite.h"
#include <vector>

namespace basicgame {
    
    class Frame {
    public:
        void add(Sprite* ny);
        void run();
        ~Frame();
    private:
        std::vector<Sprite*> sprites; // En vector av Sprite-objekt-pekare
        void forAll( void(Sprite::*mpek)(int, int), int x, int y);
        // Ovan: (medlemspekare till en funktion i klassen Sprite -vilken tar 2 int som args, int 1, int 2)
    };
    
}

#endif /* defined(__BasicGame__Frame__) */
