//
//  Sprite.cpp
//  BasicGame
//
//  Created by Ida Svensson on 2013-12-05.
//  Copyright (c) 2013 Ida Svensson. All rights reserved.
//

#include "Sprite.h"

namespace basicgame {
    
    Sprite::Sprite(int x, int y){
    }
    
    Rectangle Sprite::getRect() {
        return rect;
    }
    
    Sprite::~Sprite(){
    }
    
    void Sprite::keyDown(int key) {
    }
    
    void Sprite::tick(std::vector<Sprite*> sprites) {
        
    }
    /*
    void Sprite::setPosition(int x, int y) {
        getRect()->x = x;
        getRect()->y = y;
    }
    */
} // namespace basicgame