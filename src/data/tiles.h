#ifndef TILES_H
#define TILES_H

#include <stdint.h>

typedef struct {
    uint16_t* pixels;
    uint16_t* colors;
} Tile;

extern Tile tileMap[];

#endif