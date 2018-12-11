#define SDL_MAIN_HANDLED
#include "aiv_unit_test.h"
#include "gfx.h"

TEST(clock_rotation)
{
	int x1, x2, y1, y2;
	calculate_clock_sec_lancet(100, 100, 0, 100, &x1, &y1, &x2, &y2);
	ASSERT_THAT(x1 == 100);
	ASSERT_THAT(y1 == 100);
	ASSERT_THAT(x2 == 100);
	ASSERT_THAT(y2 == 0);
}
TEST(clock_rotation_half)
{
	int x1, x2, y1, y2;
	calculate_clock_sec_lancet(100, 100, 30000, 100, &x1, &y1, &x2, &y2);
	ASSERT_THAT(x1 == 100);
	ASSERT_THAT(y1 == 100);
	ASSERT_THAT(x2 == 100);
	ASSERT_THAT(y2 == 200);
}
TEST(clock_rotation_full)
{
	int x1, x2, y1, y2;
	calculate_clock_sec_lancet(100, 100, 60000, 100, &x1, &y1, &x2, &y2);
	ASSERT_THAT(x1 == 100);
	ASSERT_THAT(y1 == 100);
	ASSERT_THAT(x2 == 100);
	ASSERT_THAT(y2 == 0);
}
TEST(clock_rotation_full_and_half)
{
	int x1, x2, y1, y2;
	calculate_clock_sec_lancet(100, 100, 90000, 100, &x1, &y1, &x2, &y2);
	ASSERT_THAT(x1 == 100);
	ASSERT_THAT(y1 == 100);
	ASSERT_THAT(x2 == 100);
	ASSERT_THAT(y2 == 200);
}
TEST(clock_rotation_full_and_quarter)
{
	int x1, x2, y1, y2;
	calculate_clock_sec_lancet(100, 100, 75000, 100, &x1, &y1, &x2, &y2);
	ASSERT_THAT(x1 == 100);
	ASSERT_THAT(y1 == 100);
	ASSERT_THAT(x2 == 200);
	ASSERT_THAT(y2 == 100);
}
int main(int argc, char **argv)
{

	RUN_TEST(clock_rotation);
	RUN_TEST(clock_rotation_half);
	RUN_TEST(clock_rotation_full);
	RUN_TEST(clock_rotation_full_and_half);
	RUN_TEST(clock_rotation_full_and_quarter);

	PRINT_TEST_RESULTS();

	return 0;
}
