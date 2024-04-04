#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <compress/zx0.h>
#include <input.h>
#include <sound.h>

#include "data/levels.h"
#include "data/palette.h"
#include "keys.h"
#include "screen.h"

bool Game_isLevelFinished(const Game* self) {
    for (uint8_t i = 0; i < 16 * 12; i++) {
        if (self->currentState[i] == TileTarget) {
            return false;
        }
    }
    return true;
}

void Game_drawScoreCard(const Game* self) {
    char str[9];
    sprintf(str, "%05d|%02d", self->currentSteps, self->currentLevel);
    drawText(16, 6, str);
}

void Game_drawFull(const Game* self) {
    uint8_t i = 0;
    for (uint8_t y = 0; y < 12; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            drawTile(x, y, self->currentState[i], 0, 0);
            i++;
        }
    }
    Player_draw(&self->player, 0, 0);
    fillBottomBar(0x00, 0x22);
    Game_drawScoreCard(self);
}

void Game_drawLevelTile(const Game* self,
                        uint8_t x,
                        uint8_t y,
                        int8_t halfOffsetX,
                        int8_t halfOffsetY) {
    uint8_t i = y * 16 + x;
    drawTile(x, y, self->currentState[i], halfOffsetX, halfOffsetY);
}

bool Game_moveCrate(Game* self, uint8_t x, uint8_t y, int8_t dx, int8_t dy) {
    uint8_t nx = x + dx;
    uint8_t ny = y + dy;

    if (nx > 15 || ny > 11) {
        return 0;
    }

    uint8_t nextTile = self->currentState[ny * 16 + nx];
    if (nextTile != TileEmpty && nextTile != TileTarget) {
        return false;
    }

    uint8_t curTile = self->currentState[y * 16 + x];
    if (curTile == TileCrateB) {
        self->currentState[y * 16 + x] = TileEmpty;
    } else {
        self->currentState[y * 16 + x] = TileTarget;
    }

    if (nextTile == TileEmpty) {
        self->currentState[ny * 16 + nx] = TileCrateB;
    } else {
        self->currentState[ny * 16 + nx] = TileCrateG;
    }

    return true;
}

void Game_startLevel(Game* self, uint8_t level) {
    if (level > 15) {
        self->allFinished = true;
        return;
    }

    dzx0_standard(levels[level - 1], self->currentState);
    self->currentLevel = level;
    self->currentSteps = 0;
    self->allFinished  = false;
    uint8_t playerPosX;
    uint8_t playerPosY;

    // replace the player with an empty tile but remember the coordinates
    for (uint8_t n = 0; n < 16 * 12; n++) {
        if (self->currentState[n] == TileAlienLeft1) {
            self->currentState[n] = TileEmpty;
            playerPosY            = n / 16;
            playerPosX            = n - (playerPosY * 16);
        }
    }

    Player_reset(&self->player, playerPosX, playerPosY);

    // replace first 4 tiles with score card background
    self->currentState[0] = TileScoreCard1;
    self->currentState[1] = TileScoreCard2;
    self->currentState[2] = TileScoreCard3;
    self->currentState[3] = TileScoreCard4;

    Game_drawFull(self);
}

void Game_enter(Game* self) {
    self->allSteps = 0;
    clearScreen();
    setPalette(gamePalette);
    Game_startLevel(self, 1);
}

void Game_animateMovement(const Game* self,
                          uint8_t nx,
                          uint8_t ny,
                          int8_t dx,
                          int8_t dy,
                          bool crateMoved,
                          bool crateOnTarget) {
    if (crateMoved) {
        Game_drawLevelTile(self, nx + dx, ny + dy, -dx, -dy);  // draw the crate halfway
    }
    Game_drawLevelTile(self, nx - dx, ny - dy, 0, 0);  // redraw the tile where we moved from
    Player_draw(&self->player, -dx, -dy);              // draw the player halfway

    msleep(100);

    if (crateMoved) {
        Game_drawLevelTile(self, nx + dx, ny + dy, 0, 0);  // draw the crate fully
    }
    Game_drawLevelTile(self, nx - dx, ny - dy, 0, 0);  // redraw the tile we moved from
    Player_draw(&self->player, 0, 0);                  // draw the player fully
    Game_drawScoreCard(self);

    if (crateOnTarget) {
        bit_beepfx(BEEPFX_ITEM_3);
        msleep(30);
    } else if (crateMoved) {
        bit_beepfx(BEEPFX_GRAB_1);
        msleep(70);
    } else {
        bit_beepfx(BEEPFX_PICK);
        msleep(80);
    }
}

void Game_movePlayer(Game* self, int8_t dx, int8_t dy) {
    uint8_t nx = self->player.posX + dx;
    uint8_t ny = self->player.posY + dy;

    uint8_t nextTile   = self->currentState[ny * 16 + nx];
    bool crateMoved    = false;
    bool crateOnTarget = false;

    // if there is a crate in the way try to move it
    if (nextTile == TileCrateB || nextTile == TileCrateG) {
        // if it didn't move player can't move either
        if (!Game_moveCrate(self, nx, ny, dx, dy)) {
            Player_shrug(&self->player, dx);
            return;
        }
        crateMoved = true;
        if (self->currentState[(ny + dy) * 16 + (nx + dx)] == TileCrateG) {
            crateOnTarget = true;
        }
        nextTile = self->currentState[ny * 16 + nx];
    }

    // if the next tile is not empty or target, player can't move there
    if (nextTile != TileEmpty && nextTile != TileTarget) {
        Player_shrug(&self->player, dx);
        return;
    }

    Player_moveBy(&self->player, dx, dy);
    self->currentSteps++;

    // animate changes
    Game_animateMovement(self, nx, ny, dx, dy, crateMoved, crateOnTarget);
}

void Game_update(Game* self) {
    if (in_KeyPressed(KeyUp) || in_KeyPressed(KeyQ) || in_KeyPressed(KeyW)) {
        Game_movePlayer(self, 0, -1);
    }

    if (in_KeyPressed(KeyRight) || in_KeyPressed(KeyD)) {
        Game_movePlayer(self, 1, 0);
    }

    if (in_KeyPressed(KeyDown) || in_KeyPressed(KeyS)) {
        Game_movePlayer(self, 0, 1);
    }

    if (in_KeyPressed(KeyLeft) || in_KeyPressed(KeyA)) {
        Game_movePlayer(self, -1, 0);
    }

    if (in_KeyPressed(KeySpace)) {
        bit_beepfx(BEEPFX_SELECT_6);
        Game_startLevel(self, self->currentLevel);
    }

    if (!self->allFinished && Game_isLevelFinished(self)) {
        bit_beepfx(BEEPFX_SELECT_5);
        self->allSteps += self->currentSteps;
        Game_startLevel(self, self->currentLevel + 1);
    }

    Player_update(&self->player);
}
