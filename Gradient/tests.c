#include "aiv_unit_test.h"
#define SDL_MAIN_HANDLED
#define STB_IMAGE_IMPLEMENTATION
#include <SDL.h>
#include "gfx.h"
static SDL_Window *window;
static SDL_Renderer *renderer;
TEST(valid_texture)
{
	SDL_Texture *texture = get_colored_texture(renderer, 768, 768);
	ASSERT_THAT(texture != NULL);
	SDL_DestroyTexture(texture);
}
TEST(invalid_texture)
{
	SDL_Texture *texture = get_colored_texture(renderer, -768, 768);
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

	window = SDL_CreateWindow("Image_Loader", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 768, 768, 0);
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

	RUN_TEST(valid_texture);
	RUN_TEST(invalid_texture);

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
