#pragma once

#include "raylib.h"
#include "Sprite.h"
#include "FireCommand.h"

namespace Game {
    struct AlienShip : public Sprite {
        using Sprite::Sprite;

        std::shared_ptr<FireCommand> fireCommand = nullptr;

        bool destroyed = false;

        void fire();
    };
}
