#include <vector>
#include <memory>

#include "raylib.h"

#include "AlienShipController.h"
#include "game.h"
#include <iostream>
Game::AlienShipController::AlienShipController(std::vector<std::shared_ptr<Game::AlienShip>> &alienShips, Texture2D alienShipTexture, std::vector<std::shared_ptr<Game::Bullet>> &bullets) : alienShips(alienShips) {
    Vector2 position = startPosition;
    Vector2 defaultBulletDirection = {0.0, +1.0};

    std::shared_ptr<FireCommand> fireCommand = std::make_shared<FireCommand>(bullets, defaultBulletDirection);

    for (int row = 0; row <= numberOfRows - 1; row++) {
        for (int column = 0; column <= shipsPerRow - 1; column++) {
            alienShips.push_back(std::make_shared<Game::AlienShip>(alienShipTexture,
                                                                   position,
                                                                   true));
            alienShips.back()->fireCommand = fireCommand;

            position.x += (float) alienShipTexture.width + marginHorizontal;
        }
        position.x = startPosition.x;
        position.y += (float) alienShipTexture.width + marginVertical;
    }
}

void Game::AlienShipController::Update() {
    if (Game::frameCounter % 60 == 0) {
        if (alienShips[shipsPerRow - 1]->pos.x >= (float) Game::ScreenWidth - (float) alienShipTexture.width ||
            // TODO: This will need some extra spacing on the right side to work perfectly
            (alienShips[0]->pos.x < 0))
            alienShipsSpeed.x *= -1.0f;

        for (auto &alienShip : this->alienShips) {
            alienShip->pos.x += alienShipsSpeed.x;
        }
    }

    // TODO: Of course with this, only the last row of alien ships can fire. This is just for testing...
    if (Game::frameCounter % fireFrequency == 0) {
        int lastShipLastRow = shipsPerRow * numberOfRows;
        int firstShipLastRow = lastShipLastRow - (shipsPerRow - 1);

        int randomShipFromLastRow = GetRandomValue(firstShipLastRow, lastShipLastRow);
        std::cout << "---> " << randomShipFromLastRow << std::endl;

        if (!alienShips[randomShipFromLastRow-1]->destroyed)
            alienShips[randomShipFromLastRow-1]->fire();
    }
}
