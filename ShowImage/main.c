#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "gfx.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define WINDOW_W 960
#define WINDOW_H 540

int main(int argc, char **argv)
{
    int ret_value = 0;

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
    {
        SDL_Log("Unable to initialize sdl2: %s\n", SDL_GetError());
        ret_value = -1;
        goto cleanup;
    }

    SDL_Window *window = SDL_CreateWindow("Image_Loader", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_W, WINDOW_H, 0);
    if (!window)
    {
        SDL_Log("Unable to initialize window: %s\n", SDL_GetError());
        ret_value = -1;
        goto cleanup_sdl;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer)
    {
        SDL_Log("Unable to initialize renderer: %s\n", SDL_GetError());
        ret_value = -1;
        goto cleanup_window;
    }

    if (argc <= 1)
    {
        SDL_Log("Unable to find path.");
        ret_value = -1;
        goto cleanup_renderer;
    }

    register int i;
    char *path;
    for (i = 1; i < argc; i++)
    {
        path = argv[i];
    }
    int x, y, n;

    SDL_Texture *texture = load_image_on_texture(path, renderer, &x, &y, &n);
    if(!texture)
    {
        SDL_Log("Unable to load image from path %s.\n", path);
        ret_value = -1;
        goto cleanup_renderer;
    }

    for (;;)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                goto cleanup_renderer;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Rect rect;
        rect.x = 0;
        rect.y = 0;
        rect.w = WINDOW_W;
        rect.h = WINDOW_H;
        SDL_RenderCopy(renderer, texture, NULL, &rect);

        SDL_RenderPresent(renderer);
    }

cleanup_renderer:
    SDL_DestroyRenderer(renderer);
cleanup_window:
    SDL_DestroyWindow(window);
cleanup_sdl:
    SDL_Quit();
cleanup:
    return ret_value;
}