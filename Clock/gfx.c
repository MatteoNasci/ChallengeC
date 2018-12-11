#include "gfx.h"
#include <stdio.h>
void calculate_clock_sec_lancet(int origin_x, int origin_y, Uint32 current_ms_time, int lancet_len, int *x1, int *y1, int *x2, int *y2)
{
    *x1 = origin_x;
    *y1 = origin_y;

    Uint32 temp = current_ms_time % MINUTE_IN_MS;
    float rot_value = (float)temp / MINUTE_IN_MS * M_PI * 2;

    *x2 = (int)(sinf(rot_value) * lancet_len) + origin_x;
    *y2 = -(int)(cosf(rot_value) * lancet_len) + origin_y;
}