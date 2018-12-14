#include "gfx.h"
SDL_Texture *load_image_on_texture(const char *const filename, SDL_Renderer *const renderer, int *const x, int *const y, int *const n)
{
    unsigned char *data = stbi_load(filename, x, y, n, 0);
    if (data == NULL)
    {
        return NULL;
    }

    // transfer image data into texture
    unsigned char *pixel;

    // load texture
    SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB24, SDL_TEXTUREACCESS_STREAMING, *x, *y);

    if (!texture)
    {
        stbi_image_free(data);
        return NULL;
    }

    // number of bytes on a single line
    int pitch = 0;

    // Lock texture in order to modify it
    if (SDL_LockTexture(texture, NULL, (void **)&pixel, &pitch))
    {
        stbi_image_free(data);
        return NULL;
    }

    // clear texture data
    SDL_memset(pixel, 0, *x * *y * *n);

    // put texture data into pixels. The third parameter is the number of byte of the image
    SDL_memcpy(pixel, data, *x * *y * *n);

    // relase the texture
    SDL_UnlockTexture(texture);

    stbi_image_free(data);

    return texture;
}