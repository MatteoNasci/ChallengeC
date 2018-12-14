#include "utils.h"
#include <string.h>
char* ignore_first_char(char *const str)
{
    if(strlen(str) <= 1)
    {
        return NULL;
    }
    return str + 1;
}