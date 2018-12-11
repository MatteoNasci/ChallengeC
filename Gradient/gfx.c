#include "gfx.h"
SDL_Texture *get_colored_texture(SDL_Renderer *renderer, int x, int y)
{
    // transfer image data into texture
    unsigned char *pixel;

    // load texture
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, x, y);

    if (!texture)
    {
        return NULL;
    }

    // number of bytes on a single line
    int pitch = 0;

    // Lock texture in order to modify it
    if (SDL_LockTexture(texture, NULL, (void **)&pixel, &pitch))
    {
        return NULL;
    }

    const size_t size = x * y * 3;
    SDL_memset(pixel, 0, size);

    // put texture data into pixels. The third parameter is the number of byte of the image
    register int i;
    int h;
    int w;
    unsigned char value;
    for (i = 0; i < size; i ++)
    {
        h = i / pitch * 3;
        w = i % pitch;

        value = (unsigned char)((float)MAX_BYTE_2 * h / pitch + (float)MAX_BYTE_2 * w / pitch);
        pixel[i] = value;
    }

    // relase the texture
    SDL_UnlockTexture(texture);
    return texture;
}