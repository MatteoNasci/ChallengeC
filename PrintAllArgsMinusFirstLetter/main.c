#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        printf("This program requires at least one argument to be passed!\n");
        return -1;
    }

    while (*(++argv))
    {
        char *to_print = ignore_first_char(*argv);
        printf("%s\n", to_print);
    }

    return 0;
}