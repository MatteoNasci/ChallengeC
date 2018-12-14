#include "utils.h"
void reverse_text(char *const to_fill, const char *const to_revert, const int size)
{
    register int i;
    for (i = 0; i < size; i++)
    {
        to_fill[i] = to_revert[size - 1 - i];
    }
    to_fill[size] = '\0';
}