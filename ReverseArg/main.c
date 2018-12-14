#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("This program requires one argument to be passed!\n");
        return -1;
    }

    const int text_size = strlen(argv[1]);

    char *reverted = malloc((text_size + 1) * sizeof(char));

    reverse_text(reverted, argv[1], text_size);

    printf("%s\n", reverted);

    free(reverted);

    return 0;
}