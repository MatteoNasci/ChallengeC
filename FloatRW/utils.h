#define FILE_ERROR_OPENFILE -1
#define FILE_ERROR_READ -2
#define FILE_ERROR_WRITE -3
#define FILE_ERROR_CLOSE -4
#define FILE_ERROR_SEEK -5
#define FILE_NO_ERROR 0
#include <stdio.h>
int write_on_file(const void *const buffer, const size_t data_size, const size_t data_num, const char *const filename);
int read_from_file(void *const buffer, const size_t data_size, const size_t data_num, const char *const filename);
int _open_file_internal(FILE **const file, const char *const filename, const char *const filemode);
int _close_file_internal(FILE *file);