#include "timer.h"
int is_timer_over(const Uint32 current_ms, const Uint32 last_ms, const int duration_ms)
{
    return (current_ms >= last_ms + duration_ms);
}
