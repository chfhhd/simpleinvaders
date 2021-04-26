#pragma once

#include "raylib.h"
#include "Sprite.h"

namespace Game {
    struct Player : public Sprite {
        using Sprite::Sprite;

        void ProcessInput();

        int lives = 3;
        int speed = 5;
    };
}
