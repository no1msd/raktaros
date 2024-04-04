#ifndef TILETYPES_H
#define TILETYPES_H

#include <stdint.h>

typedef enum {
    TileEmpty             = 0,
    TileFull              = 1,
    TileBrick             = 2,
    TileCrateB            = 3,
    TileCrateG            = 4,
    TileTarget            = 5,
    TileAlienLeft1        = 6,
    TileAlienLeft2        = 7,
    TileAlienLeft3        = 8,
    TileAlienRight1       = 9,
    TileAlienRight2       = 10,
    TileAlienRight3       = 11,
    TileScoreCard1        = 12,
    TileScoreCard2        = 13,
    TileScoreCard3        = 14,
    TileScoreCard4        = 15,
    TileLeftBar           = 16,
    TileTopBar            = 17,
    TileRightBar          = 18,
    TileBottomBar         = 19,
    TileTopRightInBar     = 20,
    TileTopLeftInBar      = 21,
    TileBottomRightInBar  = 22,
    TileBottomLeftInBar   = 23,
    TileTopRightOutBar    = 24,
    TileTopLeftOutBar     = 25,
    TileBottomRightOutBar = 26,
    TileBottomLeftOutBar  = 27,
} TileType;

#endif