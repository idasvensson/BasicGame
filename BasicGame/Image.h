//
//  Image.h
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-18.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#ifndef __BasicGame__Image__
#define __BasicGame__Image__

#include "SDL/SDL.h"
#include <string>

namespace basicgame {
    
    class Image {
    
    public:
        Image(std::string filename, bool transparent); // Konstruktor
        Image(); // Defaultkonstruktor
        Image(const Image& other); // Copykonstruktor - vid t.ex Image a(b);
        Image& operator=(const Image& other);
        ~Image();
        SDL_Surface* getSurface() const;
        
    private:
        SDL_Surface* img;
        bool isTransparent;

    };
    
}

#endif /* defined(__BasicGame__Image__) */
