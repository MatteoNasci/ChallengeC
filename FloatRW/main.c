#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
int write_floats()
{
    char *filename = "float_rw_floats";
    const float arr[ARRAY_SIZE] = {1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f};

    int result = write_on_file(arr, sizeof(float), ARRAY_SIZE, filename);

    if (result != FILE_NO_ERROR)
    {
        printf("An error occurred while writing floats on file! Error code: %d.\n", result);
        return -1;
    }
    return 0;
}
int read_floats(const char *const filename)
{
    float arr[ARRAY_SIZE] = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};

    int result = read_from_file(arr, sizeof(float), ARRAY_SIZE, filename);

    if (result != FILE_NO_ERROR)
    {
        printf("An error occurred while reading floats from file! Error code: %d.\n", result);
        return -1;
    }

    register int i;
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        printf("element %d = %f\n", i, arr[i]);
    }
    return 0;
}
int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        int res = write_floats();
        if (res)
        {
            return res;
        }
    }
    else if (argc == 2)
    {
        int res = read_floats(argv[1]);
        if (res)
        {
            return res;
        }
    }
    else
    {
        printf("This program requires either one or zero arguments!\n");
        return -1;
    }

    return 0;
}