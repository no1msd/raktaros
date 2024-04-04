#include "score.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <input.h>

#include "data/endscreen.h"
#include "data/palette.h"
#include "keys.h"
#include "screen.h"

void Score_enter(Score* self, uint16_t score) {
    self->startGame = false;

    clearScreen();
    setPalette(endScreenPalette);
    drawImage(endScreenImage);

    char str[9];
    sprintf(str, "%08d", score);
    drawText(112, 116, str);
}

void Score_update(Score* self) {
    if (in_KeyPressed(KeySpace)) {
        self->startGame = true;
    }
}