#include "tiles.h"

uint16_t alienLeft1Pixels[] = {
        0xffff,  // ################
        0xdffb,  // ##### #### #####
        0xbffd,  // ###### ## ######
        0x1ff8,  // #####      #####
        0xeff7,  // #### ###### ####
        0xc7ea,  // ### # # ##   ###
        0xe7ea,  // ### # # ###  ###
        0xc3cf,  // ##  ######    ##
        0x618e,  // #   ###  ##    #
        0xc5af,  // # # ######   # #
        0xe7ef,  // ### #######  ###
        0x0ff0,  // ####        ####
        0x9ff9,  // #####  ##  #####
        0x87e1,  // ###    ##    ###
        0xffff,  // ################
        0xffff,  // ################
};

uint16_t alienColors[] = {
        0x0000,
        0x5005,
        0x5005,
        0x3443,
};

uint16_t alienLeft2Pixels[] = {
        0xffff,  // ################
        0xbffd,  // ###### ## ######
        0xbffd,  // ###### ## ######
        0x1ff8,  // #####      #####
        0xeff7,  // #### ###### ####
        0xc7ea,  // ### # # ##   ###
        0xe7ea,  // ### # # ###  ###
        0xc3cf,  // ##  ######    ##
        0x618e,  // #   ###  ##    #
        0xc5af,  // # # ######   # #
        0xe7ef,  // ### #######  ###
        0x0ff0,  // ####        ####
        0x9ff9,  // #####  ##  #####
        0x87e1,  // ###    ##    ###
        0xffff,  // ################
        0xffff,  // ################
};

uint16_t alienLeft3Pixels[] = {
        0xffff,  // ################
        0xdffb,  // ##### #### #####
        0xbffd,  // ###### ## ######
        0x1ff8,  // #####      #####
        0xeff7,  // #### ###### ####
        0xc7ea,  // ### # # ##   ###
        0xe5aa,  // # # # # ###  # #
        0xc18f,  // #   ######     #
        0x63ce,  // ##  ###  ##   ##
        0xc7ef,  // ### ######   ###
        0xe7ef,  // ### #######  ###
        0x0ff0,  // ####        ####
        0x9ff9,  // #####  ##  #####
        0x87e1,  // ###    ##    ###
        0xffff,  // ################
        0xffff,  // ################
};

uint16_t alienRight1Pixels[] = {
        0xffff,  // ################
        0xdffb,  // ##### #### #####
        0xbffd,  // ###### ## ######
        0x1ff8,  // #####      #####
        0xeff7,  // #### ###### ####
        0x57e3,  // ###   ## # # ###
        0x57e7,  // ###  ### # # ###
        0xf3c3,  // ##    ######  ##
        0x7186,  // #    ##  ###   #
        0xf5a3,  // # #   ###### # #
        0xf7e7,  // ###  ####### ###
        0x0ff0,  // ####        ####
        0x9ff9,  // #####  ##  #####
        0x87e1,  // ###    ##    ###
        0xffff,  // ################
        0xffff,  // ################
};

uint16_t alienRight2Pixels[] = {
        0xffff,  // ################
        0xbffd,  // ###### ## ######
        0xbffd,  // ###### ## ######
        0x1ff8,  // #####      #####
        0xeff7,  // #### ###### ####
        0x57e3,  // ###   ## # # ###
        0x57e7,  // ###  ### # # ###
        0xf3c3,  // ##    ######  ##
        0x7186,  // #    ##  ###   #
        0xf5a3,  // # #   ###### # #
        0xf7e7,  // ###  ####### ###
        0x0ff0,  // ####        ####
        0x9ff9,  // #####  ##  #####
        0x87e1,  // ###    ##    ###
        0xffff,  // ################
        0xffff,  // ################
};

uint16_t alienRight3Pixels[] = {
        0xffff,  // ################
        0xdffb,  // ##### #### #####
        0xbffd,  // ###### ## ######
        0x1ff8,  // #####      #####
        0xeff7,  // #### ###### ####
        0x57e3,  // ###   ## # # ###
        0x55a7,  // # #  ### # # # #
        0xf183,  // #     ######   #
        0x73c6,  // ##   ##  ###  ##
        0xf7e3,  // ###   ###### ###
        0xf7e7,  // ###  ####### ###
        0x0ff0,  // ####        ####
        0x9ff9,  // #####  ##  #####
        0x87e1,  // ###    ##    ###
        0xffff,  // ################
        0xffff,  // ################
};

uint16_t bottomBarPixels[] = {
        0xffff,  // ################
        0xffff,  // ################
        0xaaaa,  // # # # # # # # #
        0x5555,  //  # # # # # # # #
        0xaaaa,  // # # # # # # # #
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
};

uint16_t barColors[] = {
        0x2222,
        0x2222,
        0x2222,
        0x2222,
};

uint16_t bottomLeftInBarPixels[] = {
        0xfeff,  // ###############
        0xfcff,  // ##############
        0xa8aa,  // # # # # # # #
        0x5455,  //  # # # # # # #
        0xa8aa,  // # # # # # # #
        0x3400,  //           ## #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
};

uint16_t bottomLeftOutBarPixels[] = {
        0x6800,  //          ## #
        0x7500,  //          ### # #
        0x2a00,  //           # # #
        0x1500,  //            # # #
        0x0a00,  //             # #
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
};

uint16_t bottomRightInBarPixels[] = {
        0xffff,  // ################
        0xffff,  // ################
        0xaaea,  // ### # # # # # #
        0x55d5,  // ## # # # # # # #
        0xaaea,  // ### # # # # # #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
};

uint16_t bottomRightOutBarPixels[] = {
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00a8,  // # # #
        0x0050,  //  # #
        0x00a0,  // # #
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
};

uint16_t brickPixels[] = {
        0x0000,  //
        0xf7f7,  // #### ####### ###
        0xe7e7,  // ###  ######  ###
        0x5555,  //  # # # # # # # #
        0x0000,  //
        0x7f7f,  //  ####### #######
        0x7e7e,  //  ######  ######
        0x5555,  //  # # # # # # # #
        0x0000,  //
        0xf7f7,  // #### ####### ###
        0xe7e7,  // ###  ######  ###
        0x5555,  //  # # # # # # # #
        0x0000,  //
        0x7f7f,  //  ####### #######
        0x7e7e,  //  ######  ######
        0x5555,  //  # # # # # # # #
};

uint16_t brickColors[] = {
        0x7667,
        0x6677,
        0x6776,
        0x7766,
};

uint16_t crateBrownPixels[] = {
        0x0000,  //
        0xfe7f,  //  ##############
        0xfe7f,  //  ##############
        0x0000,  //
        0x0460,  //  ##          #
        0xd66d,  //  ## ## ### # ##
        0xb46b,  //  ## # ### ## #
        0x7667,  //  ##  ### ### ##
        0xe46e,  //  ## ### ###  #
        0xd66d,  //  ## ## ### # ##
        0xb46b,  //  ## # ### ## #
        0x7667,  //  ##  ### ### ##
        0x0000,  //
        0xfe7f,  //  ##############
        0x5455,  //  # # # # # # #
        0x0000,  //
};

uint16_t crateBrownColors[] = {
        0x8888,
        0x9b89,
        0xab8a,
        0xbbbb,
};

uint16_t crateGreenPixels[] = {
        0x0000,  //
        0xfe7f,  //  ##############
        0xfe7f,  //  ##############
        0x0000,  //
        0xf46f,  //  ## ######## #
        0x2662,  //  ##   #   #  ##
        0x4464,  //  ##  #   #   #
        0x8668,  //  ## #   #    ##
        0x1461,  //  ##    #   # #
        0x2662,  //  ##   #   #  ##
        0x4464,  //  ##  #   #   #
        0x8668,  //  ## #   #    ##
        0x0000,  //
        0xfe7f,  //  ##############
        0x5455,  //  # # # # # # #
        0x0000,  //
};

uint16_t crateGreenColors[] = {
        0xcccc,
        0xdfcd,
        0xefce,
        0xffff,
};

uint16_t emptyPixels[] = {
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
};

uint16_t emptyColors[] = {
        0x0000,
        0x0000,
        0x0000,
        0x0000,
};

uint16_t fullPixels[] = {
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
};

uint16_t leftBarPixels[] = {
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
};

uint16_t rightBarPixels[] = {
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
};

uint16_t scoreCard1Pixels[] = {
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0xff0f,  //     ############
        0xff0f,  //     ############
        0xff0f,  //     ############
        0xff07,  //      ###########
        0xe703,  //       #####  ###
        0xe701,  //        ####  ###
        0xff00,  //         ########
        0x7f00,  //          #######
        0x3f00,  //           ######
        0x1f00,  //            #####
        0x0000,  //
};

uint16_t scoreCard1Colors[] = {
        0x2222,
        0x0020,
        0x1122,
        0x2422,
};

uint16_t scoreCard2Pixels[] = {
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0x0000,  //
};

uint16_t scoreCard2Colors[] = {
        0x2222,
        0x0000,
        0x0000,
        0x4444,
};

uint16_t scoreCard3Pixels[] = {
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0xfffb,  // ##### ##########
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xffff,  // ################
        0xfffb,  // ##### ##########
        0x0000,  //
};

uint16_t scoreCard4Pixels[] = {
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x00f8,  // #####
        0x00fc,  // ######
        0x00fe,  // #######
        0x00ff,  // ########
        0x80e7,  // ###  ####
        0xc0e7,  // ###  #####
        0xe0ff,  // ###########
        0xf0ff,  // ############
        0xf0ff,  // ############
        0xf0ff,  // ############
        0x0000,  //
};

uint16_t scoreCard4Colors[] = {
        0x2222,
        0x2202,
        0x2211,
        0x4244,
};

uint16_t targetPixels[] = {
        0xffff,  // ################
        0xffff,  // ################
        0x67e6,  // ###  ##  ##  ###
        0x63c6,  // ##   ##  ##   ##
        0xf3cf,  // ##  ########  ##
        0xffff,  // ################
        0xffff,  // ################
        0xf3cf,  // ##  ########  ##
        0xf3cf,  // ##  ########  ##
        0xffff,  // ################
        0xffff,  // ################
        0xf3cf,  // ##  ########  ##
        0x63c6,  // ##   ##  ##   ##
        0x67e6,  // ###  ##  ##  ###
        0xffff,  // ################
        0xffff,  // ################
};

uint16_t targetColors[] = {
        0x1111,
        0x0110,
        0x0110,
        0x1111,
};

uint16_t topBarPixels[] = {
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0xffff,  // ################
        0xffff,  // ################
        0x5555,  //  # # # # # # # #
        0xaaaa,  // # # # # # # # #
        0x5555,  //  # # # # # # # #
        0x0000,  //
        0x0000,  //
};

uint16_t topLeftInBarPixels[] = {
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0x7400,  //          ### #
        0x6800,  //          ## #
        0xf4ff,  // ############ #
        0xe8ff,  // ########### #
        0x5455,  //  # # # # # # #
        0xa8aa,  // # # # # # # #
        0x5455,  //  # # # # # # #
        0x0000,  //
        0x0000,  //
};

uint16_t topLeftOutBarPixels[] = {
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0f00,  //             ####
        0x1f00,  //            #####
        0x3500,  //           ## # #
        0x6a00,  //          ## # #
        0x7500,  //          ### # #
        0x6800,  //          ## #
        0x7400,  //          ### #
};

uint16_t topRightInBarPixels[] = {
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0x00d0,  // ## #
        0x00e8,  // ### #
        0xffd3,  // ## #  ##########
        0xffef,  // ### ############
        0x55d5,  // ## # # # # # # #
        0xaaea,  // ### # # # # # #
        0x55d5,  // ## # # # # # # #
        0x0080,  // #
        0x0000,  //
};

uint16_t topRightOutBarPixels[] = {
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x0000,  //
        0x00c0,  // ##
        0x00e0,  // ###
        0x0050,  //  # #
        0x00a8,  // # # #
        0x0050,  //  # #
        0x0028,  //   # #
        0x0050,  //  # #
};

Tile tileMap[] = {
        {emptyPixels, emptyColors},            // TileEmpty
        {fullPixels, barColors},               // TileFull
        {brickPixels, brickColors},            // TileBrick
        {crateBrownPixels, crateBrownColors},  // TileCrateB
        {crateGreenPixels, crateGreenColors},  // TileCrateG
        {targetPixels, targetColors},          // TileTarget
        {alienLeft1Pixels, alienColors},       // TileAlienLeft1
        {alienLeft2Pixels, alienColors},       // TileAlienLeft2
        {alienLeft3Pixels, alienColors},       // TileAlienLeft3
        {alienRight1Pixels, alienColors},      // TileAlienRight1
        {alienRight2Pixels, alienColors},      // TileAlienRight2
        {alienRight3Pixels, alienColors},      // TileAlienRight3
        {scoreCard1Pixels, scoreCard1Colors},  // TileScoreCard1
        {scoreCard2Pixels, scoreCard2Colors},  // TileScoreCard2
        {scoreCard3Pixels, scoreCard2Colors},  // TileScoreCard3
        {scoreCard4Pixels, scoreCard4Colors},  // TileScoreCard4
        {leftBarPixels, barColors},            // TileLeftBar
        {topBarPixels, barColors},             // TileTopBar
        {rightBarPixels, barColors},           // TileRightBar
        {bottomBarPixels, barColors},          // TileBottomBar
        {topRightInBarPixels, barColors},      // TileTopRightInBar
        {topLeftInBarPixels, barColors},       // TileTopLeftInBar
        {bottomRightInBarPixels, barColors},   // TileBottomRightInBar
        {bottomLeftInBarPixels, barColors},    // TileBottomLeftInBar
        {topRightOutBarPixels, barColors},     // TileTopRightOutBar
        {topLeftOutBarPixels, barColors},      // TileTopLeftOutBar
        {bottomRightOutBarPixels, barColors},  // TileBottomRightOutBar
        {bottomLeftOutBarPixels, barColors},   // TileBottomLeftOutBar
};
