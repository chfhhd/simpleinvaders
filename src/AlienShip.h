#pragma once

#include "raylib.h"
#include "Sprite.h"

namespace Game {
    struct AlienShip : public Sprite {
        using Sprite::Sprite;

        bool destroyed = false;
    };
}
