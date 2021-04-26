#include "raylib.h"

#include "GameScreen.h"
#include "game.h"

Game::GameScreen::GameScreen() {
    // Your screen initialization code here...
    alienShipTexture = LoadTexture("assets/graphics/alien.png");
    playerTexture = LoadTexture("assets/graphics/player.png");

    alienShipController = std::make_unique<Game::AlienShipController>(alienShips, alienShipTexture);

    Vector2 playerStartPosition;
    playerStartPosition.x = (float) Game::ScreenWidth / 2 - (float) playerTexture.width / 2;
    playerStartPosition.y = (float) Game::ScreenHeight - (float) playerTexture.height;
    player = std::make_shared<Game::Player>(playerTexture,
                                            playerStartPosition,
                                            true);
}

Game::GameScreen::~GameScreen() {
    // Your screen cleanup code here...
    UnloadTexture(alienShipTexture);
    UnloadTexture(playerTexture);
}

void Game::GameScreen::ProcessInput() {
    // Your process input code here...
    player->ProcessInput();
}

void Game::GameScreen::Update() {
    // Your update game code here...
    alienShipController->Update();
}

void Game::GameScreen::Draw() {
    // Your drawing code here...
    ClearBackground(RAYWHITE);

    DrawTexture(player->texture, (int) player->pos.x, (int) player->pos.y, RAYWHITE);

    for (const auto &alienShip : this->alienShips) {
        if (!alienShip->destroyed)
            DrawTexture(alienShip->texture, (int) alienShip->pos.x, (int) alienShip->pos.y, RAYWHITE);
    }
}
