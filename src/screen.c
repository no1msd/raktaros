#include "screen.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <compress/zx0.h>

#include "data/font.h"
#include "data/tiles.h"

#define CONTROL_ADDR 0xe000
#define PALETTE_ADDR 0xe020
#define COLORS_ADDR 0xe080
#define PIXELS_MONO_ADDR 0xe800
#define PIXELS_COLOR_ADDR 0xe700

#define undefined 0xff

bool monochrome() {
    static bool mono = undefined;
    if (mono == undefined) {
        mono = (bpeek(0) != 0xc3);
    }
    return mono;
}

uint8_t* pixelsPtr() {
    if (monochrome()) {
        return (uint8_t*)PIXELS_MONO_ADDR;
    }
    return (uint8_t*)PIXELS_COLOR_ADDR;
}

void clearScreen() {
    if (monochrome()) {
        memset(pixelsPtr(), 0, 0x1800);
        return;
    }

    memset(CONTROL_ADDR, 0, 0x2000);
}

void setPalette(uint16_t* palette) {
    if (monochrome()) {
        return;
    }

    for (uint8_t i = 0; i < 16; i++) {
        wpoke(PALETTE_ADDR + i * 2, palette[i]);
        wpoke(PALETTE_ADDR + 0x20 + i * 2, palette[i]);
        wpoke(PALETTE_ADDR + 0x40 + i * 2, palette[i]);
    }

    // select the first palette
    bpoke(CONTROL_ADDR + 1, 0x01 | 0x80);
}

void drawImage(uint8_t* data) {
    // first 2 bytes are the length of the color chunk
    uint16_t colorLen = *((uint16_t*)data);

    if (monochrome()) {
        // on the monochrome primo we just have to uncompress the 256x192 pixel data, which
        // starts after the 4 bytes of size information and the color information
        dzx0_standard(data + 4 + colorLen, pixelsPtr());
        return;
    }

    // second 2 bytes are the length of the 256x192 pixel data chunk
    uint16_t pixelLen = *((uint16_t*)(data + 2));

    // for the color primo just extract all 3 chunks of data to the video memory after skipping
    // the 4 bytes of size information
    dzx0_standard(data + 4, COLORS_ADDR);
    dzx0_standard(data + 4 + colorLen, pixelsPtr());
    dzx0_standard(data + 4 + colorLen + pixelLen, pixelsPtr() + 0x1800);
}

void drawTile(uint8_t x, uint8_t y, TileType tile, int8_t halfOffsetX, int8_t halfOffsetY) {
    uint16_t addr = pixelsPtr() + y * 0x200 + x * 2 + halfOffsetY * 0x100 + halfOffsetX;
    for (uint8_t i = 0; i < 16; i++) {
        wpoke(addr, tileMap[tile].pixels[i]);
        addr += 0x20;
    }

    if (monochrome()) {
        return;
    }

    addr = COLORS_ADDR + y * 0x80 + halfOffsetY * 0x40 + x * 2 + halfOffsetX;
    for (uint8_t i = 0; i < 4; i++) {
        wpoke(addr, tileMap[tile].colors[i]);
        addr += 0x20;
    }
}

void drawText(uint8_t x, uint8_t y, const char* str) {
    uint16_t pixels[16];
    memset(pixels, 0, sizeof(pixels));

    for (uint8_t n = 0; n < 8; n++) {
        uint8_t* charPixels = font[10];
        if (str[n] >= '0' && str[n] <= '9') {
            charPixels = font[str[n] - '0'];
        }

        for (uint8_t row = 0; row < 8; row++) {
            pixels[n / 4 + row * 2] |= (uint16_t)charPixels[row] << (((3 - n % 4) + 2) % 4 * 4);
        }
    }

    for (uint8_t row = 0; row < 8; row++) {
        wpoke(pixelsPtr() + x / 8 + (y + row) * 0x20, pixels[0 + row * 2]);
        wpoke(pixelsPtr() + x / 8 + 2 + (y + row) * 0x20, pixels[1 + row * 2]);
    }
}

void fillBottomBar(uint8_t pixel, uint8_t color) {
    if (monochrome()) {
        return;
    }

    memset(pixelsPtr() + 0x1800, pixel, 0x100);
    memset(COLORS_ADDR + 0x600, color, 0x40);
}

void copyScreenRectangle(uint8_t* dest, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
    for (uint16_t i = 0; i < height; i++) {
        memcpy(dest + i * width / 8, pixelsPtr() + (y + i) * 0x20 + x / 8, width / 8);
    }
}

void drawRectangle(uint8_t* src, uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
    for (uint16_t i = 0; i < height; i++) {
        memcpy(pixelsPtr() + (y + i) * 0x20 + x / 8, src + i * width / 8, width / 8);
    }
}

void clearRectangle(uint8_t x, uint8_t y, uint8_t width, uint8_t height) {
    for (uint16_t i = 0; i < height; i++) {
        memset(pixelsPtr() + (y + i) * 0x20 + x / 8, 0, width / 8);
    }
}