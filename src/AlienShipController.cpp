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

            position.x += (float) alienShipTexture.width + marginHorizontal;
        }
        position.x = startPosition.x;
        position.y += (float) alienShipTexture.width + marginVertical;
    }
}

Game::AlienShipController::~AlienShipController() {
}

void Game::AlienShipController::Update() {
    if (Game::frameCounter % 60 == 0) {
        if (alienShips[shipsPerRow-1]->pos.x >= (float) Game::ScreenWidth - (float)alienShipTexture.width  ||   // TODO: This will need some extra spacing on the right side to work perfectly
            (alienShips[0]->pos.x < 0))
            alienShipsSpeed.x *= -1.0f;

        for (auto &sprite : this->alienShips)
            sprite->pos.x += alienShipsSpeed.x;
    }
}
