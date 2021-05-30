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
    {  0, 224 },{  21, 224 },{  43, 224 },{  64, 160},{  64, 160},{  21, 160},{  0, 160},
    {  0, 120 },{  21, 120 },{  43, 120 },{  64, 100 }, {  43, 80 },{  21, 80 },{  0, 80 },
    {  0, 40 },{  21, 40 },{  43, 40 },{  64, 40 },{  43, 0 },{  10, 0 }
    }, {
    // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        4
} };// 0, 40, 80, 120, 160, 224    // 0, 21, 43, 64
#endif

void matrix_init_kb(void) {
	matrix_init_user();
};
