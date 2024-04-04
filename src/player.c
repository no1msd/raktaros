#include "player.h"

#include <stdlib.h>
#include <string.h>

#include <sound.h>

#include "screen.h"
#include "tiletypes.h"

void Player_reset(Player* self, uint8_t posX, uint8_t posY) {
    self->posX        = posX;
    self->posY        = posY;
    self->facingLeft  = true;
    self->idleAnim    = false;
    self->idleCounter = 255;
}

void Player_draw(const Player* self, int8_t halfOffsetX, int8_t halfOffsetY) {
    TileType playerTile = TileAlienRight1;
    if (self->facingLeft) {
        playerTile = TileAlienLeft1;
    }
    playerTile += self->idleAnim;
    drawTile(self->posX, self->posY, playerTile, halfOffsetX, halfOffsetY);
}

void Player_shrug(Player* self, int8_t dx) {
    if (dx != 0) {
        self->facingLeft = dx < 0;
    }

    TileType playerTile = TileAlienLeft3;
    if (!self->facingLeft) {
        playerTile = TileAlienRight3;
    }

    drawTile(self->posX, self->posY, playerTile, 0, 0);

    msleep(200);
    Player_draw(self, 0, 0);
    msleep(70);
    bit_beepfx(BEEPFX_DROP_1);
}

void Player_moveBy(Player* self, int8_t dx, int8_t dy) {
    if (dx != 0) {
        self->facingLeft = dx < 0;
    }

    self->posX += dx;
    self->posY += dy;
}

void Player_update(Player* self) {
    self->idleCounter--;
    if (self->idleCounter == 0) {
        self->idleCounter = 64 + self->idleAnim * 191;
        self->idleAnim    = !self->idleAnim;
        Player_draw(self, 0, 0);
    }
}