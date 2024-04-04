#ifndef TITLE_H
#define TITLE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t flashCounter;
    uint8_t flashingData[42];
    bool flashVisible;
    bool startGame;
    uint8_t melodyIndex;
    uint8_t soundPatchIndex;
} Title;

void Title_enter(Title* self);
void Title_update(Title* self);

#endif