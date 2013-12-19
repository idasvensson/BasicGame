//
//  Rectangle.h
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__Rectangle__
#define __BasicGame__Rectangle__

#include "SDL/SDL.h"

namespace basicgame {
    
    struct Rectangle : public SDL_Rect
    {
        Rectangle();
        Rectangle(int xx, int yy, int ww, int hh);
        bool contains(int xx, int yy) const; // Koordinataritmetik
        Rectangle centeredRect(int width, int height) const; // Returnerar en rektangel som är centrerad inuti den egna rektangeln, t.ex. för att centrera text
        bool overlaps(const Rectangle& other) const; // OBS: Endast på rektangelnivå, inte bra för kollisionsdetektering
        
    };
    
} // namespace basicgame

#endif /* defined(__BasicGame__Rectangle__) */
