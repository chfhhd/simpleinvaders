#include "raylib.h"

#include "GameScreen.h"
#include "game.h"
#include "config.h"
#include "FireCommand.h"

Game::GameScreen::GameScreen() {
    // Your screen initialization code here...
    LoadTextures();

    InitPlayer();

    InitBullets();

    alienShipController = std::make_unique<Game::AlienShipController>(alienShips, alienShipTexture, bullets);
}

void Game::GameScreen::LoadTextures() {
    alienShipTexture = LoadTexture("assets/graphics/alien.png");
    playerTexture = LoadTexture("assets/graphics/player.png");
    bulletTexture = LoadTexture("assets/graphics/bullet.png");
}

void Game::GameScreen::InitPlayer() {
    Vector2 playerStartPosition;
    playerStartPosition.x = (float) ScreenWidth / 2 - (float) playerTexture.width / 2;
    playerStartPosition.y = (float) ScreenHeight - (float) playerTexture.height;
    player = std::make_shared<Player>(playerTexture,
                                      playerStartPosition,
                                      true);

    Vector2 defaultBulletDirection = {0.0, -1.0};
    player->fireCommand = std::make_unique<FireCommand>(bullets, defaultBulletDirection);
}

void Game::GameScreen::InitBullets() {
    Vector2 position{-100.0, -100.0};

    for (int n = 0; n < numberOfBullets; n++) {
        bullets.push_back(std::make_shared<Game::Bullet>(bulletTexture,
                                                         position,
                                                         false));
    }
}

Game::GameScreen::~GameScreen() {
    // Your screen cleanup code here...
    UnloadTexture(alienShipTexture);
    UnloadTexture(playerTexture);
    UnloadTexture(bulletTexture);
}

void Game::GameScreen::ProcessInput() {
    // Your process input code here...
    player->ProcessInput();
}

void Game::GameScreen::Update() {
    // Your update game code here...
    alienShipController->Update();

    Rectangle collRectangle;
    for (auto &bullet : this->bullets) {
        bullet->move();
        if (bullet->active) {
            collRectangle = {player->pos.x, player->pos.y, (float) player->texture.width, (float) player->texture.height};
            if(CheckCollisionPointRec(bullet->pos, collRectangle)) {
                player->lives--;
            }

            for (const auto &alienShip : this->alienShips) {
                if (!alienShip->destroyed) {
                    collRectangle = {alienShip->pos.x, alienShip->pos.y, (float) alienShip->texture.width,
                                     (float) alienShip->texture.height};

                    if (CheckCollisionPointRec(bullet->pos, collRectangle)) {
                        alienShip->destroyed = true;
                        bullet->active = false;
                    }
                }
            }
        }
    }

}

void Game::GameScreen::Draw() {
    // Your drawing code here...
    ClearBackground(RAYWHITE);

    DrawTexture(player->texture, (int) player->pos.x, (int) player->pos.y, RAYWHITE);

    for (const auto &alienShip : this->alienShips) {
        if (!alienShip->destroyed)
            DrawTexture(alienShip->texture, (int) alienShip->pos.x, (int) alienShip->pos.y, RAYWHITE);
    }

    for (const auto &bullet : this->bullets) {
        if (bullet->active)
            DrawTexture(bullet->texture, (int) bullet->pos.x, (int) bullet->pos.y, RAYWHITE);
    }

    std::stringstream livesString;
    livesString << "Lives: " << player->lives;
    DrawText(livesString.str().c_str(), 5, Game::ScreenHeight-50, 25, BLACK);
}
