#pragma once

#include "raylib.h"

#include "Sprite.h"

class Command {
public:
    virtual ~Command() = default;
    
    virtual void execute(Game::Sprite* sprite) = 0;
};
