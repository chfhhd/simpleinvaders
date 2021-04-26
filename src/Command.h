#pragma once

#include "Sprite.h"

class Command {
public:
    virtual void execute(Game::Sprite* sprite) = 0;
};
