#include <SDL.h>
#include "stb_image.h"
SDL_Texture *load_image_on_texture(const char *const filename, SDL_Renderer *const renderer, int *const x, int *const y, int *const n);