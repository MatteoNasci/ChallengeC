#include "aiv_unit_test.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
TEST(process_string_ciao)
{
	char text[] = {"ciao"};
	char* result = ignore_first_char(text);
	ASSERT_THAT(result != NULL);
	ASSERT_THAT(strcmp(result,"iao") == 0);
	ASSERT_THAT(strlen(result) == 3);
}
TEST(process_string_supercalifragilisticarelipitoso)
{
	char text[] = {"supercalifragilisticarelipitoso"};
	char* result = ignore_first_char(text);
	ASSERT_THAT(result != NULL);
	ASSERT_THAT(strcmp(result,"upercalifragilisticarelipitoso") == 0);
	ASSERT_THAT(strlen(result) == 30);
}
TEST(process_invalid_string_one_letter)
{
	char text[] = {"a"};
	char* result = ignore_first_char(text);
	ASSERT_THAT(result == NULL);
}
TEST(process_invalid_string_zero_letter)
{
	char text[] = {""};
	char* result = ignore_first_char(text);
	ASSERT_THAT(result == NULL);
}
int main(int argc, char **argv)
{
	RUN_TEST(process_invalid_string_zero_letter);
	RUN_TEST(process_invalid_string_one_letter);
	RUN_TEST(process_string_supercalifragilisticarelipitoso);
	RUN_TEST(process_string_ciao);
	PRINT_TEST_RESULTS();
	return 0;
}
