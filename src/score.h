#ifndef SCORE_H
#define SCORE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    bool startGame;
} Score;

void Score_enter(Score* self, uint16_t score);
void Score_update(Score* self);

#endif