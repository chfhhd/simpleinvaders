#include <vector>

#include "raylib.h"

#include "AlienShipController.h"
#include "game.h"

Game::AlienShipController::AlienShipController(std::vector<std::shared_ptr<Game::AlienShip>> &alienShips, Texture2D alienShipTexture) : alienShips(alienShips) {
    Vector2 position = startPosition;
    for (int row = 0; row <= numberOfRows - 1; row++) {
        for (int column = 0; column <= shipsPerRow - 1; column++) {
            alienShips.push_back(std::make_shared<Game::AlienShip>(alienShipTexture,
                                                                   position,
                                                                   true));

            position.x += (float) alienShipTexture.width + margin_x;
        }
        position.x = startPosition.x;
        position.y += (float) alienShipTexture.width + margin_y;
    }
}

Game::AlienShipController::~AlienShipController() {
}

void Game::AlienShipController::Update() {
    if (Game::frameCounter % 60 == 0) {
        if ((alienShips[10]->pos.x >= ((float) Game::ScreenWidth - (float) alienShipTexture.width)) ||
            (alienShips[0]->pos.x < 0))
            alienShipsSpeed.x *= -1.0f;

        for (auto &sprite : this->alienShips)
            sprite->pos.x += alienShipsSpeed.x;
    }
}
