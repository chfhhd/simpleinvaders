#pragma once

#include "raylib.h"
#include "Sprite.h"

namespace Game {
    struct Bullet : public Sprite {
        using Sprite::Sprite;

        float speed = 10.0;
        Vector2 direction = {0.0, -1.0};

        bool IsOutOfScreen();

        void move();
    };
}
