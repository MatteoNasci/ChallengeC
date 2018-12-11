#include <SDL.h>

#include "stb_image.h"
SDL_Texture* load_image_on_texture(char *filename, SDL_Renderer *renderer, int *x, int *y, int *n);