#include "aiv_unit_test.h"
#include "utils.h"
#include <stdlib.h>
#include <string.h>
TEST(revert_string_ciao)
{
	char text[] = {"ciao"};
	char *rev = malloc(5 * sizeof(char));
	reverse_text(rev, text, 4);
	ASSERT_THAT(strlen(rev) == 4);
	ASSERT_THAT(strcmp(rev, "oaic") == 0);
	free(rev);
}
TEST(revert_string_supercalifragilisticarelipitoso)
{
	char text[] = {"supercalifragilisticarelipitoso"};
	char *rev = malloc(32 * sizeof(char));
	reverse_text(rev, text, 31);
	ASSERT_THAT(strlen(rev) == 31);
	ASSERT_THAT(strcmp(rev, "osotipileracitsiligarfilacrepus") == 0);
	free(rev);
}
int main(int argc, char **argv)
{
	RUN_TEST(revert_string_ciao);
	RUN_TEST(revert_string_supercalifragilisticarelipitoso);
	PRINT_TEST_RESULTS();
	return 0;
}
