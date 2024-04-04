#ifndef SCREEN_H
#define SCREEN_H

#include <stdbool.h>
#include <stdint.h>

#include "tiletypes.h"

// Clear the screen including color and palette data if it's a color primo.
void clearScreen();

// Store the given palette for all 3 possible palettes in video memory. Does nothing on a
// monochrome primo.
void setPalette(uint16_t* palette);

// Draw a single 16x16 tile. The x and y are tile coordinates, so the maximum is 16x12. The half
// offsets will move the tile 8 pixels in the x or y direction.
void drawTile(uint8_t x, uint8_t y, TileType tile, int8_t halfOffsetX, int8_t halfOffsetY);

// Draw an image to fill the entire screen.
//
// An image consists of 3 chunks of data compressed with zx0:
// - 1600 bytes of color information + 64 bytes padding
// - 6144 bytes of pixel data for the top 256x192 part of the screen
// - 256 bytes of pixel data for the bottom 256x8 part of the screen
//
// For the color PRIMO all 3 chunks can be uncompressed directly to video memory for the full
// 256x200 color image. For the monochrome PRIMO only the second chunk is needed for a 256*192
// monochrome image.
//
// Since all chunks are compressed we need to store their compressed size as well, so the image
// is expected to start with two 16 bit unsigned integers, the size of the first chunk and
// second chunk respectively.
void drawImage(uint8_t* data);

// Draw a strictly 8 characters long string consisting of numbers and the character '|' to the
// given coordinates. The x and y are in screen coordinates, but for expected results it must
// align with 8x1 pixel chunks.
void drawText(uint8_t x, uint8_t y, const char* str);

// Fill the bottom 8 rows of the 256x200 screen with the given pixel and color data. It won't do
// anything on a monochrome primo.
void fillBottomBar(uint8_t px, uint8_t color);

// Copy the pixel data from the given rectangle from the video memory to the given uint8_t*
// destination. It must already have enough space allocated. The x, y, width and height are in
// screen coordinates, but for expected results it must align with 8x1 pixel chunks.
void copyScreenRectangle(uint8_t* dest, uint8_t x, uint8_t y, uint8_t width, uint8_t height);

// Draw the pixel data from src to the video memory for the given rectangle. The x, y, width and
// height are in screen coordinates, but for expected results it must align with 8x1 pixel
// chunks.
void drawRectangle(uint8_t* src, uint8_t x, uint8_t y, uint8_t width, uint8_t height);

// Clear the pixel data in video memory for the given rectangle. The x, y, width and height are
// in screen coordinates, but for expected results it must align with 8x1 pixel chunks.
void clearRectangle(uint8_t x, uint8_t y, uint8_t width, uint8_t height);

#endif