#include "aiv_unit_test.h"
#include "utils.h"

/*
int write_on_file(const void *const buffer, const size_t data_size, const size_t data_num, const char *const filename);
int read_from_file(void *const buffer, const size_t data_size, const size_t data_num, const char *const filename);
int _open_file_internal(FILE **const file, const char *const filename, const char *const filemode);
int _close_file_internal(FILE *file);
*/
TEST(close_file)
{
	FILE *file;
	if (!fopen_s(&file, "main.c", "r"))
	{
		ASSERT_THAT(_close_file_internal(file) == FILE_NO_ERROR);
	}
}
TEST(close_invalid_file)
{
	FILE *file = NULL;
	ASSERT_THAT(_close_file_internal(file) == FILE_ERROR_CLOSE);
}
TEST(open_file)
{
	FILE *file;
	ASSERT_THAT(_open_file_internal(&file, "main.c", "r") == FILE_NO_ERROR);
	fclose(file);
}
TEST(open_invalid_file)
{
	FILE *file;
	ASSERT_THAT(_open_file_internal(&file, "bralal.c", "r") == FILE_ERROR_OPENFILE);
}
TEST(write_on_file)
{
	long long values[3] = {15, 11, 154};
	ASSERT_THAT(write_on_file(values, sizeof(long long), 3, "float_rw_tests") == FILE_NO_ERROR);
}
TEST(write_on_file_invalid_data)
{
	long long *values = NULL;
	ASSERT_THAT(write_on_file(values, sizeof(long long), 3, "float_rw_tests") == FILE_ERROR_WRITE);
}
TEST(write_on_file_invalid_file)
{
	long long values[3] = {15, 11, 154};
	ASSERT_THAT(write_on_file(values, sizeof(long long), 3, "") == FILE_ERROR_OPENFILE);
}
TEST(read_on_file)
{
	long long values[3] = {0, 0, 0};
	ASSERT_THAT(read_from_file(values, sizeof(long long), 3, "float_rw_tests") == FILE_NO_ERROR);
}
TEST(read_on_file_invalid_data)
{
	long long *values = NULL;
	ASSERT_THAT(read_from_file(values, sizeof(long long), 3, "float_rw_tests") == FILE_ERROR_READ);
}
TEST(read_on_file_invalid_size)
{
	long long values[3] = {0, 0, 0};
	ASSERT_THAT(read_from_file(values, 100, 3, "float_rw_tests") == FILE_ERROR_READ);
}
TEST(read_on_file_invalid_num)
{
	long long values[3] = {0, 0, 0};
	ASSERT_THAT(read_from_file(values, sizeof(long long), 100, "float_rw_tests") == FILE_ERROR_READ);
}
TEST(read_on_file_invalid_file)
{
	long long values[3] = {0, 0, 0};
	ASSERT_THAT(read_from_file(values, sizeof(long long), 3, "invented_file") == FILE_ERROR_OPENFILE);
}
int main(int argc, char **argv)
{
	RUN_TEST(close_file);
	RUN_TEST(close_invalid_file);
	RUN_TEST(open_file);
	RUN_TEST(open_invalid_file);
	RUN_TEST(write_on_file_invalid_data);
	RUN_TEST(write_on_file_invalid_file);
	RUN_TEST(write_on_file);
	RUN_TEST(read_on_file);
	RUN_TEST(read_on_file_invalid_data);
	RUN_TEST(read_on_file_invalid_size);
	RUN_TEST(read_on_file_invalid_num);
	RUN_TEST(read_on_file_invalid_file);
	PRINT_TEST_RESULTS();
	return 0;
}
