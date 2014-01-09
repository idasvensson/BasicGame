//
//  Sprite.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "Sprite.h"
using namespace std;

namespace basicgame {
    
    Sprite::Sprite(int x, int y, int xVel, int yVel, string filename, bool transparent) : image(filename, transparent)
    {
        
    }
    
    Rectangle Sprite::getRect()
    {
        return rect;
    }
    
    Sprite::~Sprite()
    {
    }
    
    void Sprite::keyDown(int key)
    {
    }
    
    void Sprite::keyUp(int key)
    {
    }
    
    void Sprite::tick(std::vector<Sprite*> sprites)
    {
    }
    
    void Sprite::setXVel(int newVel)
	{
		xVel = newVel;
	}
    
	void Sprite::setYVel(int newVel)
	{
		yVel = newVel;
	}
    
	int Sprite::getXVel()
	{
		return xVel;
	}
    
	int Sprite::getYVel()
	{
		return yVel;
	}
    
    void Sprite::setImage(string filename, bool transparent)
    {
        //img
    }
    /*
    void Sprite::setPosition(int x, int y) {
        getRect()->x = x;
        getRect()->y = y;
    }
    */
} // namespace basicgame