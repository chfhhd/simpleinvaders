#include <vector>
#include <memory>

#include "raylib.h"

#include "AlienShipController.h"
#include "game.h"

Game::AlienShipController::AlienShipController(std::vector<std::shared_ptr<Game::AlienShip>> &alienShips,
                                               Texture2D alienShipTexture,
                                               std::vector<std::shared_ptr<Game::Bullet>> &bullets) : alienShips(
        alienShips) {
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
    MoveShips();
    Fire();
}

bool Game::AlienShipController::FreeToFire(int check) {
    check += shipsPerRow;
    while (check <= alienShips.size()) {
        if (!alienShips[check - 1]->destroyed)
            return false;
        check += shipsPerRow;
    }
    return true;
}

void Game::AlienShipController::Fire() {
    if (frameCounter % fireFrequency == 0) {
        int randomShipID = GetRandomValue(1, (int) alienShips.size());
        while (alienShips[randomShipID - 1]->destroyed || !FreeToFire(randomShipID)) {
            randomShipID = GetRandomValue(1, (int) alienShips.size());
        }
        alienShips[randomShipID - 1]->fire();
    }
}

void Game::AlienShipController::MoveShips() {
    if (frameCounter % 60 == 0) {
        if (alienShips[shipsPerRow - 1]->pos.x >= (float) ScreenWidth - (float) alienShips[shipsPerRow - 1]->texture.width || alienShips[0]->pos.x < 0.0)
            alienShipsSpeed.x *= -1.0f;

        for (auto &alienShip : alienShips) {
            alienShip->pos.x += alienShipsSpeed.x;
        }
    }
}
