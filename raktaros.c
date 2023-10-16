#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <input.h>

#include "tiledata.h"

/*

TODO
----

[ ] title screen
[ ] a képkirajzolás közben a secondary képernyőn "n. szint"
[X] space -> restart
[X] billentyűismétlés
[ ] lépésmérés és szintkijelzés
[ ] legalább 10 pálya
[ ] alien arra nézzen amerre megy (jobbra vagy balra)
[ ] mozgáskor fél lépés animáció
[ ] idle mozgás alienre
[ ] end screen (gratulálok, 10 szintet hány lépésben teljesítette, press space to restart)
[ ] fehér keret a pálya köré ha elfér
[ ] alsó sáv legyen kitöltve
[ ] Primo A/B support
[ ] képmódváltás 4x4-re normálisan?
[ ] hang (normális lépés, doboztolás, doboz helyére ment)
[ ] többféle irányítási lehetőség
[ ] pici animáció ha nem tud menni?
[ ] betöltéskor Raktáros szép magyar ékezettel legyen a fájlnév? :)
[ ] cleanup, lint, github release

*/

#define SCREEN_WIDTH 256
#define SCREEN_HEIGHT 200

#define SCREEN_PAGE_START 0xE000
#define SCREEN_PAGE_END 0xFFFF

const uint16_t paletteStart = SCREEN_PAGE_START + 32;
const uint16_t pixelStart   = SCREEN_PAGE_END - (SCREEN_WIDTH * SCREEN_HEIGHT) / 8 + 1;
const uint16_t colorStart   = (SCREEN_PAGE_END - (SCREEN_WIDTH * SCREEN_HEIGHT) / 8 + 1) -
                            SCREEN_HEIGHT / 4 * 32 - 2 * 32;

typedef struct Tile {
    uint16_t* pixels;
    uint16_t* colors;
} Tile;

Tile tileMap[] = {
        {emptyPixels, emptyColors},
        {fullPixels, fullColors},
        {brickPixels, brickColors},
        {cratePixels, crateColorsBrown},
        {cratePixels, crateColorsGreen},
        {targetPixels, targetColors},
        {playerPixels, playerColors},
};

const uint8_t TileEmpty  = 0;
const uint8_t TileFull   = 1;
const uint8_t TileBrick  = 2;
const uint8_t TileCrateB = 3;
const uint8_t TileCrateG = 4;
const uint8_t TileTarget = 5;
const uint8_t TilePlayer = 6;

// 14*9

// clang-format off
uint8_t level1[] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,2,2,2,2,2,1,1,1,1,1,
    1,1,1,1,2,2,2,0,0,0,2,1,1,1,1,1,
    1,1,1,1,2,5,6,3,0,0,2,1,1,1,1,1,
    1,1,1,1,2,2,2,0,3,5,2,1,1,1,1,1,
    1,1,1,1,2,5,2,2,3,0,2,2,1,1,1,1,
    1,1,1,1,2,0,2,0,5,0,0,2,1,1,1,1,
    1,1,1,1,2,3,0,4,3,3,5,2,1,1,1,1,
    1,1,1,1,2,0,0,0,5,0,0,2,1,1,1,1,
    1,1,1,1,2,2,2,2,2,2,2,2,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

uint8_t level2[] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,1,2,2,2,2,2,2,2,2,2,2,2,1,1,1,
    1,2,2,0,0,0,0,0,0,2,0,0,2,1,1,1,
    1,2,0,0,2,5,0,0,0,2,0,0,2,1,1,1,
    1,2,0,0,0,0,0,0,5,2,0,0,2,1,1,1,
    1,2,2,3,3,2,2,6,2,2,3,3,2,2,2,1,
    1,1,2,0,0,2,5,0,0,0,0,0,0,0,2,1,
    1,1,2,0,0,2,0,0,0,0,5,2,0,0,2,1,
    1,1,2,0,0,2,0,0,0,0,0,0,0,2,2,1,
    1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1,
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};
// clang-format on

uint8_t* levels[] = {level1, level2};

void initScreen() {
    // reset everything to 0
    for (int i = SCREEN_PAGE_START; i <= SCREEN_PAGE_END; i++) {
        bpoke(i, 0x00);
    }

    // select 4x4 mode
    bpoke(SCREEN_PAGE_START, 0x00);

    // select the first palette
    bpoke(SCREEN_PAGE_START + 1, 0x01);

    // set palette bg colors
    wpoke(paletteStart + 0, 0xffff);
    wpoke(paletteStart + 2, 0xffff);
    wpoke(paletteStart + 4, 0x53ff);
    wpoke(paletteStart + 6, 0xa4c8);
    wpoke(paletteStart + 8, 0xacac);
    wpoke(paletteStart + 10, 0xacac);
    wpoke(paletteStart + 12, 0x7575);
    wpoke(paletteStart + 14, 0x7575);

    // set palette fg colors
    wpoke(paletteStart + 16, 0x9200);
    wpoke(paletteStart + 18, 0xc009);
    wpoke(paletteStart + 20, 0x0580);
    wpoke(paletteStart + 22, 0x4040);
    wpoke(paletteStart + 24, 0xd000);
    wpoke(paletteStart + 26, 0x4068);
    wpoke(paletteStart + 28, 0x9900);
    wpoke(paletteStart + 30, 0x082c);
}

void putPixel(uint8_t x, uint8_t y) {
    uint16_t f  = (uint16_t)y * SCREEN_WIDTH + x;
    uint16_t px = pixelStart + f / 8;
    bpoke(px, bpeek(px) | (0x80 >> (f % 8)));
}

void drawTile(uint8_t x, uint8_t y, uint16_t* pixels, uint16_t* colors) {
    uint16_t px = pixelStart + y * 32 * 16 + x * 2;
    for (uint8_t i = 0; i < 16; i++) {
        wpoke(px, pixels[i]);
        px += 32;
    }

    px = colorStart + y * 4 * 32 + x * 2;
    for (uint8_t i = 0; i < 4; i++) {
        wpoke(px, colors[i]);
        px += 32;
    }
}

typedef struct Game {
    uint8_t currentState[16 * 12];
    uint8_t playerX;
    uint8_t playerY;
    uint8_t currentLevel;
} Game;

void Game_startLevel(Game* game) {
    memcpy(game->currentState, levels[game->currentLevel], sizeof(game->currentState));
    uint8_t i = 0;
    for (uint8_t y = 0; y < 12; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            if (game->currentState[i] == TilePlayer) {
                game->currentState[i] = TileEmpty;
                game->playerX         = x;
                game->playerY         = y;
            }
            i++;
        }
    }
}

void Game_drawPlayer(Game* game) {
    drawTile(game->playerX,
             game->playerY,
             tileMap[TilePlayer].pixels,
             tileMap[TilePlayer].colors);
}

void Game_drawFull(Game* game) {
    uint8_t i = 0;
    for (uint8_t y = 0; y < 12; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            drawTile(x,
                     y,
                     tileMap[game->currentState[i]].pixels,
                     tileMap[game->currentState[i]].colors);
            i++;
        }
    }
    Game_drawPlayer(game);
}

void Game_drawTile(Game* game, uint8_t x, uint8_t y) {
    uint8_t i = y * 16 + x;
    drawTile(x,
             y,
             tileMap[game->currentState[i]].pixels,
             tileMap[game->currentState[i]].colors);
}

uint8_t Game_moveCrate(Game* game, uint8_t x, uint8_t y, int8_t dx, int8_t dy) {
    uint8_t nx = x + dx;
    uint8_t ny = y + dy;

    if (nx > 15 || ny > 11) {
        return 0;
    }

    uint8_t curTile  = game->currentState[y * 16 + x];
    uint8_t nextTile = game->currentState[ny * 16 + nx];

    if (nextTile == TileEmpty) {
        if (curTile == TileCrateB) {
            game->currentState[y * 16 + x] = TileEmpty;
        } else {
            game->currentState[y * 16 + x] = TileTarget;
        }
        game->currentState[ny * 16 + nx] = TileCrateB;
        Game_drawTile(game, nx, ny);
        return 1;
    } else if (nextTile == TileTarget) {
        if (curTile == TileCrateB) {
            game->currentState[y * 16 + x] = TileEmpty;
        } else {
            game->currentState[y * 16 + x] = TileCrateB;
        }
        game->currentState[ny * 16 + nx] = TileCrateG;
        Game_drawTile(game, nx, ny);
        return 1;
    }

    return 0;
}

void Game_movePlayer(Game* game, int8_t dx, int8_t dy) {
    uint8_t nx = game->playerX + dx;
    uint8_t ny = game->playerY + dy;

    if (nx > 15 || ny > 11) {
        return;
    }

    uint8_t nextTile = game->currentState[ny * 16 + nx];

    if (nextTile == TileCrateB || nextTile == TileCrateG) {
        if (!Game_moveCrate(game, nx, ny, dx, dy)) {
            return;
        }
        nextTile = game->currentState[ny * 16 + nx];
    }

    if (nextTile != TileEmpty && nextTile != TileTarget) {
        return;
    }

    uint8_t ox = game->playerX;
    uint8_t oy = game->playerY;

    game->playerX = nx;
    game->playerY = ny;

    Game_drawTile(game, ox, oy);
    Game_drawPlayer(game);
}

const uint8_t KeyLeft  = 0x0e;
const uint8_t KeyRight = 0x08;
const uint8_t KeyUp    = 0x06;
const uint8_t KeyDown  = 0x02;
const uint8_t KeySpace = 0x19;

void main(void) {
    initScreen();

    Game game;
    game.currentLevel = 1;
    Game_startLevel(&game);
    Game_drawFull(&game);

    for (;;) {
        if (in_KeyPressed(KeyUp)) {
            Game_movePlayer(&game, 0, -1);
            msleep(300);
        }

        if (in_KeyPressed(KeyRight)) {
            Game_movePlayer(&game, 1, 0);
            msleep(300);
        }

        if (in_KeyPressed(KeyDown)) {
            Game_movePlayer(&game, 0, 1);
            msleep(300);
        }

        if (in_KeyPressed(KeyLeft)) {
            Game_movePlayer(&game, -1, 0);
            msleep(300);
        }

        if (in_KeyPressed(KeySpace)) {
            Game_startLevel(&game);
            Game_drawFull(&game);
        }
    }
}
