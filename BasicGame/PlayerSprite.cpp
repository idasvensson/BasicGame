//
//  PlayerSprite.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "SDL/SDL.h"
#include "Globals.h"
#include "PlayerSprite.h"
#include <iostream>
#include <vector>
using namespace std;

namespace basicgame{

    PlayerSprite::PlayerSprite(int x, int y, int xVel, int yVel, string filename, bool transparent) :
    MovingSprite(x, y, xVel, yVel, filename, transparent)
    {
        // Initialize offsets
        rect.x = x;
        rect.y = y;
    }
    
    PlayerSprite* PlayerSprite::getInstance(int x, int y, int xVel, int yVel, string filename, bool transparent)
    {
        return new PlayerSprite(x, y, xVel, yVel, filename, transparent);
    }
    
    void PlayerSprite::draw()
    {
        // Rita ut bilden på skärmytan
        SDL_BlitSurface(image.getSurface(), NULL, sys.screen, &rect);
        
    }
    
    void PlayerSprite::keyDown(int key)
    {
        switch(key) {
        
            // Funktionspekare för tillämparen för att styra vel?
            // Möjlighet att byta image för sprite vid olika riktning?
                
            case SDLK_UP: setYVel(getYVel() - 1); break;
            case SDLK_DOWN: setYVel(getYVel() + 1); break;
            case SDLK_LEFT: setXVel(getXVel() - 1); break;
            case SDLK_RIGHT: setXVel(getXVel() + 1); break;
            // case SDLK_SPACE: Hoppa?
                
        } // switch
    }
    
    void PlayerSprite::keyUp(int key)
	{
		switch (key) {
                
			case SDLK_UP: /*setYVel(getYVel() + 1);*/ break;
			case SDLK_DOWN: /*setYVel(getYVel() - rect.h / 2);*/ break;
			case SDLK_LEFT: /*setXVel(getXVel() + rect.w / 2);*/ break;
			case SDLK_RIGHT: /*setXVel(getXVel() - rect.w / 2);*/ break;
                
		} // switch
	}
    
    void PlayerSprite::tick(std::vector<Sprite*> sprites) // Använda rect.x och rect.y eller x och y?
    {
        /*
        // Check collision with walls (optional?)
        if( rect.x < 0 ) // outside left
        {
            rect.x = 0;
            // Återställ X-vel så att man inte behöver kompensera
            setXVel(0);
        }
        
        if( rect.y < 0 ) // outside bottom
        {
            rect.y = 0;
            // Återställ Y-vel så att man inte behöver kompensera
			setYVel(0);
        }
        
        if( rect.x + rect.w > sys.SCREEN_WIDTH ) // outside right
        {
            rect.x = sys.SCREEN_WIDTH - rect.w;
            // Återställ X-vel så att man inte behöver kompensera
            setXVel(0);
        }
        
        if( rect.y + rect.h > sys.SCREEN_HEIGHT ) // outside top
        {
            rect.y = sys.SCREEN_HEIGHT - rect.h;
            // Återställ Y-vel så att man inte behöver kompensera
			setYVel(0);
        }
        */
        
        /*
        // Check collision with other sprites
        for( int i=0; sprites.size(); i++ )
        {
            if( sprites[i] != this ) {
                // hasCollided = true;
                if( rect.overlaps(sprites[i]->getRect()) )
                {
                    // För att inte fastna efter kollision - loopens ordning?
                    rect.x -= getXVel();
                    rect.y -= getYVel();
                    
                    // Avslutar vår rörelse
                    setXVel(0);
                    setYVel(0);
                    
                    // Avbryt funktionen
                    return;
                }
            }
        }
        
        // Collision handling
        
        for( int i=0; sprites.size(); i++ )
        {
            if( sprites[i] == this ) {
                return;
            } else {
                // hasCollided = true;
                if( rect.overlaps(sprites[i]->getRect()) )
                {
                    // För att inte fastna efter kollision - loopens ordning?
                    rect.x -= getXVel();
                    rect.y -= getYVel();
                    
                    // Avslutar vår rörelse
                    setXVel(0);
                    setYVel(0);
                    
                    // Avbryt funktionen
                    return;
                }
            }
        }
        */
        // State Change
        
        // Motion
        
        
        // Faktiskt rörelse av spriten i x-led. Rectens x-position låts påverkas av x-vel
		rect.x += getXVel();
        
        // Om vi når någon av kanterna i x-led
		if ((rect.x < 0) || (rect.x + rect.w > sys.SCREEN_WIDTH))
		{
			// Återställ X-vel så att man inte behöver kompensera
			setXVel(0);
		}
        
		// Samma som ovan fast y-led
		rect.y += getYVel();
        
		// Har koll på kanter i y-led
		if ((rect.y < 0) || (rect.y + rect.h > sys.SCREEN_HEIGHT))
		{
			// Återställ Y-vel så att man inte behöver kompensera
			setYVel(0);
		}

    }

    PlayerSprite::~PlayerSprite() {
		//SDL_FreeSurface(img);
		//SDL_FreeSurface(rightImg);
		//SDL_FreeSurface(leftImg);
	}
    
}