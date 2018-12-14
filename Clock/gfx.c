#include "gfx.h"
#include <stdio.h>
void calculate_clock_sec_lancet(const int origin_x, const int origin_y, const Uint32 current_ms_time, const int lancet_len, int *const x1, int *const y1, int *const x2, int *const y2)
{
    *x1 = origin_x;
    *y1 = origin_y;

    Uint32 temp = current_ms_time % MINUTE_IN_MS;
    float rot_value = (float)temp * INVERSE_MINUTE_IN_MS * M_PI * 2;

    *x2 = (int)(sinf(rot_value) * lancet_len) + origin_x;
    *y2 = -(int)(cosf(rot_value) * lancet_len) + origin_y;
}