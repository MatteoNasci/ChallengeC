#include "aiv_unit_test.h"
#define SDL_MAIN_HANDLED
#define STB_IMAGE_IMPLEMENTATION
#include <SDL.h>
#include "gfx.h"
#define WINDOW_W 400
#define WINDOW_H 400
#include "timer.h"
static SDL_Window *window;
static SDL_Renderer *renderer;
TEST(timer_over)
{
	ASSERT_THAT(is_timer_over(100, 10, 90));
}
TEST(timer_not_over)
{
	ASSERT_THAT(!is_timer_over(1000, 20, 990));
}
TEST(load_image)
{
	int x, y, n;
	ASSERT_THAT(renderer != NULL);
	SDL_Texture *texture = load_image_on_texture("unicorno.png", renderer, &x, &y, &n);
	ASSERT_THAT(texture != NULL);
	Uint32 format;
	int access, w, h;
	int res = SDL_QueryTexture(texture, &format, &access, &w, &h);
	ASSERT_THAT(res == 0);
	ASSERT_THAT(format == SDL_PIXELFORMAT_RGB24);
	SDL_DestroyTexture(texture);
}
TEST(load_invalid_image)
{
	int x, y, n;
	SDL_Texture *texture = load_image_on_texture("gfx.h", renderer, &x, &y, &n);
	ASSERT_THAT(texture == NULL);
}
TEST(load_invalid_path_image)
{
	int x, y, n;
	SDL_Texture *texture = load_image_on_texture("unicorno.h", renderer, &x, &y, &n);
	ASSERT_THAT(texture == NULL);
}

int main(int argc, char **argv)
{
	int ret_value = 0;
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		SDL_Log("Unable to initialize sdl2: %s\n", SDL_GetError());
		ret_value = -1;
		goto cleanup;
	}

	window = SDL_CreateWindow("Image_Loader", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, 0);
	if (!window)
	{
		SDL_Log("Unable to initialize window: %s\n", SDL_GetError());
		ret_value = -1;
		goto cleanup_sdl;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		SDL_Log("Unable to initialize renderer: %s\n", SDL_GetError());
		ret_value = -1;
		goto cleanup_window;
	}

	RUN_TEST(timer_over);
	RUN_TEST(timer_not_over);
	RUN_TEST(load_image);
	RUN_TEST(load_invalid_image);
	RUN_TEST(load_invalid_path_image);

	PRINT_TEST_RESULTS();

	//cleanup_renderer:
	SDL_DestroyRenderer(renderer);
cleanup_window:
	SDL_DestroyWindow(window);
cleanup_sdl:
	SDL_Quit();
cleanup:
	return ret_value;
}
