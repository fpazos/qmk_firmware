#include "rev1.h"

#ifdef RGB_MATRIX_ENABLE
    led_config_t g_led_config = { {
    // Key Matrix to LED Index
        {    15, 14,  8, 7, 0 },
        {20, 16, 13,  9, 6, 1 },
        {19, 17, 12, 10, 5, 2 },
        {    18,     11, 4, 3 }
    }, {
    // LED Index to Physical Position
        {   0, 179 }, {  21, 179 }, {  43, 179 }, {  64, 179 }, {  43, 134 }, {  21, 134 }, {   0, 134 }, {   0,  90 }, {  21,  90 }, {  43,  90 },
        {  64, 112 }, {  43,  45 }, {  21,  45 }, {   0,  45 }, {  11,   0 }, {  43,   0 }, {  64,  23 }, {  64, 224 }, {  43, 224 }, {  21, 224 },
        {   0, 224 }
    }, {
    // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4
} };
#endif

void matrix_init_kb(void) {
	matrix_init_user();
};
