#ifndef PLAYER_H
#define PLAYER_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t posX;
    uint8_t posY;
    bool facingLeft;
    bool idleAnim;
    uint8_t idleCounter;
} Player;

void Player_reset(Player* player, uint8_t posX, uint8_t posY);
void Player_draw(const Player* player, int8_t halfOffsetX, int8_t halfOffsetY);
void Player_shrug(Player* player, int8_t dx);
void Player_moveBy(Player* player, int8_t dx, int8_t dy);
void Player_update(Player* player);

#endif