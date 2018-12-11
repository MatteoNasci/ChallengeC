#include "timer.h"
int is_timer_over(Uint32 current_ms, Uint32 last_ms, int duration_ms)
{
    return (current_ms >= last_ms + duration_ms);
}
