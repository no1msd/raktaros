#ifndef GAME_H
#define GAME_H

#include <stdbool.h>
#include <stdint.h>

#include "player.h"

typedef struct {
    uint8_t currentState[16 * 12];
    uint8_t currentLevel;
    uint16_t currentSteps;
    uint16_t allSteps;
    Player player;
    bool allFinished;
} Game;

void Game_enter(Game* self);
void Game_update(Game* self);

#endif