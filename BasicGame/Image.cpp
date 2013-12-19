//
//  Image.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-18.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "Image.h"
#include "SDL_image/SDL_image.h"
#include <string>
#include <iostream>

namespace basicgame {
    
    Image::Image(std::string filename, bool transparent) : isTransparent(transparent)
    {
        // Temporära ytor
        SDL_Surface* loadedImage = NULL;
        SDL_Surface* optimizedImage = NULL;
        
        // Läs in bilden från den angivna filen
        loadedImage = IMG_Load( filename.c_str() );
        
        // Om bilden laddades
        if( loadedImage != NULL )
        {
            // Konvertera bilden till skärmens format
            // NOTE: SDL_ConvertSurface används internt inom SDL_DisplayFormat
            optimizedImage = SDL_DisplayFormat( loadedImage );
            
            // Frigör den gamla ytan
            SDL_FreeSurface( loadedImage );
            
            // Om ytan optimerades - HA MED?
            if( optimizedImage != NULL )
            {
                // Color key surface
                SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY, SDL_MapRGB( optimizedImage->format, 0, 0xFF, 0xFF ) );
            }
        }
        // Om inte angiven fil finns
        else
        {
            // Generera ett undantag
            // std::exception? try-catch?
        }
        
        // Tilldela den optimerade bilden
        img = optimizedImage;
        
        // Gör ev. bakgrunden transparent, baserat på första pixelns färg (anta 32-bitars)
        
    }
    
    Image::Image(const Image& other)
    {
        img = other.img; // Tilldela den nya kopians img värdet av originalets img
        isTransparent = other.isTransparent;
        img->refcount++;
    }
    
    Image& Image::operator=(const Image& other)
    {
        // Om det inte tilldelats värdet av sig självt
        if( this != &other ) {
            
            // Tilldelning
            img = other.img;
            isTransparent = other.isTransparent;
            img->refcount++; // eller?
            
        }
        
        // Returnera objektpekare, för att möjliggöra kedjad tilldelning
        return *this;
    }
    
    SDL_Surface* Image::getSurface() const
    {
        return img;
    }
    
    Image::~Image()
    {
        /*
        for( int i = 0; i < img->refcount; i++ )
            SDL_FreeSurface( img );
         */
        
        while(img->refcount > 0)
        {
            SDL_FreeSurface( img );
            std::cout << "Deleted img with refcount: " << img->refcount;
        }
    }
    
}