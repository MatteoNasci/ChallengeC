#include "utils.h"
int _open_file_internal(FILE **const file, const char *const filename, const char *const filemode)
{
    if (!filename || !filemode || fopen_s(file, filename, filemode))
    {
        return FILE_ERROR_OPENFILE;
    }
    if (fseek(*file, 0, SEEK_SET))
    {
        return FILE_ERROR_SEEK;
    }
    return FILE_NO_ERROR;
}
int _close_file_internal(FILE *const file)
{
    if (!file || fclose(file))
    {
        return FILE_ERROR_CLOSE;
    }
    return FILE_NO_ERROR;
}
int write_on_file(const void *const buffer, const size_t data_size, const size_t data_num, const char *const filename)
{
    const char *filemode = "w";
    FILE *file;

    int result = _open_file_internal(&file, filename, filemode);
    if (result)
    {
        return result;
    }

    if (!buffer || fwrite(buffer, data_size, data_num, file) != data_num)
    {
        _close_file_internal(file);
        return FILE_ERROR_WRITE;
    }

    return _close_file_internal(file);
}
int read_from_file(void *const buffer, const size_t data_size, const size_t data_num, const char *const filename)
{
    const char *filemode = "r";
    FILE *file;

    int result = _open_file_internal(&file, filename, filemode);
    if (result)
    {
        return result;
    }

    if (!buffer || fread(buffer, data_size, data_num, file) != data_num)
    {
        _close_file_internal(file);
        return FILE_ERROR_READ;
    }

    return _close_file_internal(file);
}