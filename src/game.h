#pragma once

#include "Screen.h"
#include "GameScreen.h"

namespace Game {
    extern Game::Screen *currentScreen;
    extern int frameCounter;

    extern const int ScreenWidth;
    extern const int ScreenHeight;
}