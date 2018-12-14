#include <SDL.h>
#include <math.h>
#define MINUTE_IN_MS 60000
#define INVERSE_MINUTE_IN_MS 0.00001666666666666666666
void calculate_clock_sec_lancet(const int origin_x, const int origin_y, const Uint32 current_ms_time, const int lancet_len, int *const x1, int *const y1, int *const x2, int *const y2);