#include "title.h"

#include <stdlib.h>
#include <string.h>

#include <input.h>
#include <sound.h>

#include "data/palette.h"
#include "data/titlescreen.h"
#include "keys.h"
#include "screen.h"

void Title_enter(Title* self) {
    self->flashCounter    = 0;
    self->flashVisible    = true;
    self->startGame       = false;
    self->melodyIndex     = 0;
    self->soundPatchIndex = 0;

    clearScreen();
    setPalette(titlePalette);
    drawImage(titleScreenImage);
    copyScreenRectangle(self->flashingData, 104, 65, 48, 7);
}

void Title_handleInput(Title* self) {
    if (in_KeyPressed(KeySpace)) {
        self->startGame = true;
    }
}

void Title_playNextSound(Title* self) {
    static char* melody[] =
            {"E", "A", "E", "B", "E", "G", "A", "E", "C", "E", "D", "E", "B", "C", "E", "B"};
    static char* soundPatches[] = {BUZZ_BASS, BUZZ_JAMBASS, BUZZ_TREMBASS, BUZZ_MID};

    buzzer_play(soundPatches[self->soundPatchIndex], melody[self->melodyIndex]);
    self->melodyIndex = (self->melodyIndex + 1) % 16;
    if (self->melodyIndex == 0) {
        self->soundPatchIndex = (self->soundPatchIndex + 1) % 4;
    }
}

void Title_flashSpaceLabel(Title* self) {
    self->flashCounter++;
    if (self->flashCounter != 3) {
        return;
    }

    if (self->flashVisible) {
        clearRectangle(104, 65, 48, 7);
    } else {
        drawRectangle(self->flashingData, 104, 65, 48, 7);
    }

    self->flashVisible = !self->flashVisible;
    self->flashCounter = 0;
}

void Title_update(Title* self) {
    Title_handleInput(self);
    Title_playNextSound(self);
    Title_handleInput(self);
    Title_flashSpaceLabel(self);
    msleep(200);
}