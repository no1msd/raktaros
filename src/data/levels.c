#include "levels.h"

// levels are 16*12 arrays of tile IDs compressed with zx0

uint8_t level1[] = {
        0x84, 0x01, 0x22, 0x19, 0x11, 0x0b, 0x18, 0x82, 0xe4, 0x3e, 0x15, 0x02, 0xfe, 0x24,
        0x12, 0x01, 0x88, 0x10, 0x02, 0xa3, 0x00, 0x92, 0xe0, 0x63, 0x05, 0x06, 0x03, 0xc6,
        0xc0, 0x28, 0x03, 0x05, 0x81, 0x14, 0x18, 0xfe, 0xdf, 0xbf, 0x7e, 0xf6, 0xc0, 0x8b,
        0x00, 0x05, 0xe1, 0x9f, 0xe0, 0xe3, 0xc7, 0x04, 0x03, 0xe4, 0x9f, 0xc0, 0xa5, 0x00,
        0x39, 0xfe, 0xf6, 0xe0, 0x3c, 0x1b, 0x13, 0xfe, 0xbb, 0x1a, 0xe6, 0x00, 0x00, 0x80,
};

uint8_t level2[] = {
        0x80, 0x01, 0x22, 0x19, 0x11, 0x12, 0x29, 0x18, 0x01, 0x84, 0x19, 0x15, 0x02,
        0x8a, 0x12, 0x01, 0x2a, 0x10, 0x02, 0x00, 0x1e, 0xf2, 0xe3, 0xe0, 0xef, 0xf0,
        0x05, 0xe0, 0x1f, 0xc0, 0xa0, 0x05, 0xbe, 0x14, 0x7d, 0xa0, 0x8e, 0x03, 0x03,
        0xf9, 0xe7, 0x06, 0xf2, 0x8f, 0xbd, 0x1b, 0x17, 0x9e, 0x7f, 0xfe, 0xe7, 0xe1,
        0x7e, 0xdf, 0x9c, 0xe0, 0x7d, 0xc2, 0xe3, 0xe0, 0x92, 0xfe, 0x18, 0x16, 0x1a,
        0x01, 0x1b, 0x13, 0x5f, 0xe3, 0x00, 0x00, 0x80,
};

uint8_t level3[] = {
        0x98, 0x01, 0x96, 0x19, 0x11, 0x21, 0x18, 0x01, 0x89, 0x10, 0x02, 0x6e, 0x12,
        0xc6, 0x67, 0x15, 0x02, 0x00, 0xa1, 0xfe, 0xf2, 0x02, 0x05, 0x02, 0x14, 0x18,
        0xc6, 0x8f, 0x00, 0xe0, 0xfb, 0xbf, 0xe0, 0xa3, 0xc7, 0x03, 0xe4, 0xf9, 0xe0,
        0xe3, 0xfc, 0xc4, 0xe0, 0xa1, 0x00, 0xf8, 0xff, 0x80, 0x7b, 0xf8, 0xf7, 0xfd,
        0xe0, 0xef, 0xff, 0xcb, 0x06, 0xc0, 0x39, 0xe1, 0xb3, 0x1b, 0x13, 0x17, 0xe0,
        0x62, 0x16, 0x1a, 0x3f, 0xdc, 0xde, 0xfe, 0xe2, 0xc0, 0x00, 0x20,
};

uint8_t level4[] = {
        0x96, 0x01, 0x26, 0x19, 0x11, 0x20, 0x18, 0x01, 0x62, 0x10, 0x02, 0x6e, 0x12,
        0xe0, 0x58, 0x8e, 0x00, 0x00, 0xa6, 0x19, 0xee, 0x15, 0x02, 0x03, 0xe0, 0xa6,
        0x5f, 0xc0, 0xe4, 0xa6, 0xbf, 0x03, 0xc0, 0x97, 0xa6, 0xf9, 0xc0, 0xa6, 0x7f,
        0xe0, 0xca, 0xa6, 0x06, 0x7e, 0xfb, 0xe0, 0x0b, 0x05, 0xcf, 0xfe, 0xe0, 0x7d,
        0xfe, 0xfe, 0xe0, 0xff, 0x20, 0x1b, 0x13, 0x6f, 0x1a, 0xe5, 0x00, 0x00, 0x80,
};

uint8_t level5[] = {
        0x81, 0x01, 0x22, 0x19, 0x11, 0x02, 0xe2, 0x18, 0xe2, 0x3d, 0x15, 0x02,
        0xfe, 0x89, 0x12, 0x01, 0x8a, 0x10, 0x02, 0x9a, 0x00, 0x05, 0x38, 0xe0,
        0x7b, 0xfc, 0xc2, 0xe0, 0xfe, 0x03, 0xfe, 0xa0, 0x48, 0x8b, 0x03, 0x06,
        0x03, 0xd3, 0xc0, 0xe4, 0xe1, 0x60, 0x63, 0x1b, 0x17, 0xc7, 0x20, 0xbd,
        0xdf, 0x13, 0xfe, 0x88, 0x1a, 0x01, 0x07, 0x00, 0x00, 0x80,
};

uint8_t level6[] = {
        0x81, 0x01, 0x22, 0x19, 0x11, 0x62, 0x18, 0x01, 0x06, 0x26, 0x10, 0x02,
        0xf6, 0x14, 0xda, 0x48, 0x19, 0x11, 0x15, 0x02, 0x00, 0x00, 0x4f, 0xc4,
        0x9e, 0x00, 0x03, 0x00, 0xda, 0x6f, 0x12, 0xe0, 0xea, 0xe8, 0x06, 0x3a,
        0xe1, 0x00, 0x58, 0xe9, 0x05, 0x03, 0xff, 0x05, 0xe0, 0xe0, 0x8f, 0x04,
        0x05, 0xda, 0xf8, 0x99, 0xa0, 0x7b, 0xa6, 0xf7, 0xff, 0xe0, 0x87, 0xfe,
        0xe3, 0xe0, 0x1b, 0x13, 0x92, 0xfe, 0x20, 0x1a, 0x01, 0x0c, 0x00, 0x02,
};

uint8_t level7[] = {
        0x98, 0x01, 0x80, 0x19, 0x11, 0x88, 0x18, 0x01, 0x22, 0x10, 0x02, 0x02, 0xf2,
        0x12, 0xe0, 0xe7, 0x00, 0xfe, 0xe2, 0xe1, 0xa6, 0xff, 0x15, 0xe1, 0xcb, 0xfa,
        0xfc, 0xe1, 0xa6, 0xe6, 0xe1, 0x00, 0x03, 0x00, 0x03, 0xfb, 0xac, 0xe3, 0x06,
        0xf7, 0xdf, 0xe0, 0xf0, 0xfd, 0xc0, 0xf9, 0xe0, 0x84, 0x05, 0x02, 0x02, 0xfa,
        0xe9, 0xe3, 0x05, 0xf9, 0xff, 0x80, 0x38, 0xe2, 0xe0, 0x40, 0xc9, 0xe0, 0x63,
        0x1b, 0x13, 0x92, 0xfe, 0x30, 0x1a, 0x01, 0x00, 0x08,
};

uint8_t level8[] = {
        0x86, 0x01, 0x24, 0x19, 0x11, 0xbc, 0x18, 0xea, 0x8e, 0x15, 0x02, 0xfe, 0x62,
        0x12, 0x01, 0x88, 0x10, 0x02, 0x68, 0x05, 0x39, 0xe0, 0x89, 0x00, 0x00, 0xbf,
        0x04, 0xe7, 0xef, 0xd9, 0xe0, 0x20, 0x05, 0x05, 0x03, 0x00, 0x03, 0x05, 0x3f,
        0xeb, 0xcb, 0xff, 0xe1, 0xfc, 0x80, 0x3e, 0xc0, 0x3c, 0x06, 0x02, 0xe0, 0x8a,
        0x1b, 0x17, 0x8e, 0x03, 0xbe, 0xf3, 0xe0, 0xfe, 0x9e, 0x67, 0xe4, 0xb8, 0x03,
        0xe0, 0x7f, 0xff, 0xf9, 0xbd, 0xfe, 0xe0, 0xe1, 0xfe, 0xf8, 0xe1, 0xff, 0x84,
        0x1b, 0x13, 0x8c, 0x1a, 0x01, 0x00, 0x02,
};

uint8_t level9[] = {
        0x96, 0x01, 0x26, 0x19, 0x11, 0xf7, 0x18, 0xee, 0x89, 0xff, 0x15, 0x02, 0x88, 0x12,
        0x01, 0x89, 0x10, 0x02, 0x6a, 0x00, 0x7f, 0x02, 0x14, 0x18, 0xe0, 0x9f, 0xef, 0x03,
        0x06, 0x03, 0xf7, 0xff, 0xff, 0xbe, 0xe0, 0xeb, 0xc5, 0x03, 0xee, 0xd9, 0xda, 0xe0,
        0x6f, 0x05, 0xff, 0xfe, 0xed, 0xd4, 0xe0, 0x1e, 0xc6, 0xfc, 0xff, 0xc0, 0x3f, 0xe4,
        0xda, 0x80, 0x03, 0x7e, 0xe4, 0x79, 0x16, 0x13, 0x1a, 0x40, 0xfe, 0xfe, 0xe4, 0x39,
        0x00, 0x7e, 0xa9, 0xfe, 0x22, 0x1b, 0x13, 0x5f, 0xc5, 0xf0, 0xfe, 0x00, 0x08,
};

uint8_t level10[] = {
        0x98, 0x01, 0x96, 0x19, 0x11, 0x20, 0x18, 0x01, 0x99, 0x19, 0x15, 0x02, 0x6f,
        0x14, 0xdd, 0xbb, 0xc8, 0xe3, 0x00, 0x9e, 0xfe, 0xd2, 0x89, 0x12, 0x10, 0xeb,
        0xfd, 0x03, 0x9f, 0xd8, 0xe0, 0xe8, 0xcc, 0x8b, 0x03, 0x06, 0x05, 0xbc, 0xff,
        0x02, 0xe0, 0x98, 0x03, 0x02, 0x03, 0x5f, 0xde, 0xff, 0x8a, 0xf9, 0x93, 0xe0,
        0xfd, 0xfe, 0xe0, 0xfe, 0xc6, 0xc0, 0x1f, 0x26, 0x78, 0x40, 0x3c, 0xfe, 0x26,
        0x12, 0x1b, 0x13, 0x46, 0xc0, 0x1a, 0x00, 0x20,
};

uint8_t level11[] = {
        0x98, 0x01, 0x82, 0x19, 0x11, 0x20, 0x18, 0x01, 0x22, 0x10, 0x02, 0x0b, 0x14,
        0x8f, 0xd6, 0xc8, 0x9e, 0x15, 0x02, 0x00, 0xff, 0x86, 0x02, 0xe3, 0x12, 0xc8,
        0xba, 0xe1, 0x03, 0xff, 0x00, 0x7e, 0xe0, 0x2b, 0x06, 0x05, 0x05, 0xbf, 0xfe,
        0xbe, 0xf8, 0xe0, 0xc6, 0xbe, 0x04, 0xff, 0xbe, 0xe7, 0xe0, 0xff, 0xb0, 0xc0,
        0xde, 0xa0, 0x6c, 0x2e, 0x03, 0xf2, 0x7d, 0xc0, 0xe6, 0xc6, 0x0f, 0x16, 0x13,
        0x13, 0x1a, 0xe1, 0x9e, 0xfe, 0xa6, 0x32, 0xe8, 0xb8, 0x1b, 0xd9, 0x97, 0x13,
        0x17, 0xff, 0xe1, 0xfe, 0xd8, 0xe6, 0xfe, 0xec, 0x1a, 0xe8, 0x00, 0x02,
};

uint8_t level12[] = {
        0x98, 0x01, 0x92, 0x19, 0x11, 0xf2, 0x18, 0xe6, 0x39, 0x15, 0x02, 0xfe, 0xbe,
        0x14, 0xdc, 0xfb, 0x10, 0xec, 0x05, 0xfa, 0xfe, 0xf0, 0xfb, 0x12, 0xe0, 0x00,
        0xa1, 0xff, 0x03, 0xbc, 0x00, 0xe0, 0xf9, 0xc3, 0xc0, 0xe0, 0xe0, 0xe7, 0xc2,
        0xf6, 0xef, 0xc0, 0x86, 0x00, 0x81, 0x06, 0xa0, 0x02, 0xa0, 0x02, 0x7d, 0xfe,
        0xf3, 0xe0, 0x87, 0xfe, 0xe0, 0xe0, 0x96, 0x1b, 0x13, 0x13, 0x17, 0x6f, 0x16,
        0x13, 0x1a, 0xff, 0xf9, 0xda, 0xfe, 0xfc, 0xe4, 0x00, 0x02,
};

uint8_t level13[] = {
        0x80, 0x01, 0x62, 0x19, 0x11, 0x06, 0x26, 0x18, 0x01, 0x20, 0x10, 0x02, 0x6e,
        0x12, 0xe0, 0x67, 0x00, 0x00, 0x03, 0x8b, 0xfb, 0x00, 0x05, 0xde, 0xe0, 0xe3,
        0xe8, 0x02, 0xfd, 0x05, 0xe5, 0xc0, 0xaa, 0x04, 0x04, 0x22, 0x14, 0x18, 0x1f,
        0xdf, 0xaf, 0xc5, 0x06, 0xf5, 0x98, 0x7e, 0xbf, 0x1b, 0x17, 0xc4, 0xfd, 0x78,
        0x9e, 0xfe, 0x88, 0x78, 0xe1, 0x5e, 0xff, 0x49, 0xff, 0xc0, 0x73, 0xfe, 0x5e,
        0x7f, 0xe0, 0x13, 0xfe, 0x8c, 0x1a, 0x01, 0x00, 0x02,
};

uint8_t level14[] = {
        0x84, 0x01, 0x62, 0x19, 0x11, 0x0b, 0x18, 0x82, 0xe6, 0x3e, 0x15, 0x02, 0xfe,
        0xfb, 0x14, 0xdd, 0xe4, 0x9b, 0xe6, 0x00, 0xeb, 0xff, 0xf4, 0x12, 0xbe, 0xe1,
        0x10, 0xe6, 0x1f, 0x03, 0x05, 0x03, 0x04, 0x00, 0xfd, 0x8e, 0xe0, 0xe5, 0x8f,
        0x05, 0xf7, 0xbd, 0xfc, 0xe0, 0xe8, 0xfe, 0x83, 0x06, 0x00, 0x83, 0xa0, 0x8f,
        0x62, 0xb7, 0xe6, 0xc0, 0x1b, 0x17, 0x02, 0x69, 0x05, 0xe6, 0x9f, 0x16, 0x1a,
        0x01, 0x5f, 0xc0, 0xfe, 0xc2, 0xe0, 0x3e, 0xfe, 0x27, 0x16, 0x13, 0xfb, 0xc2,
        0x9f, 0x13, 0xdf, 0xea, 0xfe, 0xc0, 0x00, 0x20,
};

uint8_t level15[] = {
        0x98, 0x01, 0x80, 0x19, 0x11, 0x88, 0x18, 0x01, 0x22, 0x10, 0x02, 0x02, 0xf2,
        0x12, 0xe0, 0xe7, 0x00, 0xfe, 0xe2, 0xe1, 0xa6, 0x7e, 0x15, 0x02, 0x03, 0xfd,
        0xfe, 0xee, 0xe0, 0xa6, 0x79, 0xc1, 0xfc, 0x06, 0x03, 0x05, 0xe3, 0xe0, 0x8b,
        0x05, 0x05, 0xbc, 0xca, 0xe0, 0x26, 0x00, 0x03, 0x04, 0x28, 0x02, 0x0f, 0xfe,
        0xe4, 0xc0, 0xfb, 0xc7, 0xe7, 0x04, 0xfd, 0xc1, 0x61, 0xe0, 0xf7, 0xfe, 0x83,
        0x40, 0x25, 0xe0, 0x8e, 0x1b, 0x13, 0xfe, 0x48, 0xc0, 0x1a, 0x01, 0x00, 0x20,
};

uint8_t* levels[] = {
        level1,
        level2,
        level3,
        level4,
        level5,
        level6,
        level7,
        level8,
        level9,
        level10,
        level11,
        level12,
        level13,
        level14,
        level15,
};
