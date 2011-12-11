#include "Morphling.h"

int main(int argc, char *argv[])
{
    // seed random with processor ticks, pseudorandom enough
    srand(SDL_GetTicks());


    Display dsp(TOTALWIDTH, TOTALHEIGHT);

    // seed random with processor ticks, pseudorandom enough
    srand(SDL_GetTicks());

    // draw red pixel for the lulz
    dsp.putpixel(100, 100, 255, 0, 0);
    dsp.update();

    // draw a bunch of tiles for further lulz
    dsp.draw_tile(0, 0, Display::TILE_LAVA);
    dsp.draw_tile(24, 0, Display::TILE_GRASS);
    dsp.update();

    // Poll for events, and handle the ones we care about.
    SDL_Event event;
    bool loop = true;
    while(loop)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                loop = false;
            default:
                continue;
            }
        }
    }
    return 0;
}