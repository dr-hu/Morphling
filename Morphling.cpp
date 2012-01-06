#include "Morphling.h"

Game::Game() : dsp(1024, 768), out("log.txt"), M(100, 100)
{
    out << "Welcome to Morphling. Walk around using the arrow keys. Press the space bar to generate a new map.\n";
    
    // currently we default to in-game
    state = GS_GAME;

    // Set up player -- SHOULD BE WRITTEN IN DATA FILE LATER INSTEAD OF HARDCODED
    P.setMaxHP(100);
    P.setHP(100);
    P.setPosition(20, 20);
    P_sprite = Display::SPRITE_PLAYERARROW;
    P_spritestate = Display::SPRITE_STATE_FACING_SOUTH;

    // initialize map with delicious perlin noise
    M.generate_perlin();

    redraw();
}

int Game::handle_event(SDL_Event &event)
{
    switch (state)
    {
        case GS_GAME:
            switch (event.type)
            {
              case SDL_QUIT:
                state = GS_QUIT;
              case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                  case SDLK_UP:
                    P.move(0, -1);
                    P_spritestate = Display::SPRITE_STATE_FACING_NORTH;
                    break;
                  case SDLK_RIGHT:
                    P.move(1, 0);
                    P_spritestate = Display::SPRITE_STATE_FACING_EAST;
                    break;
                  case SDLK_DOWN:
                    P.move(0, 1);
                    P_spritestate = Display::SPRITE_STATE_FACING_SOUTH;
                    break;
                  case SDLK_LEFT:
                    P.move(-1, 0);
                    P_spritestate = Display::SPRITE_STATE_FACING_WEST;
                    break;
                  case SDLK_SPACE:
                    // generate a new map
                    M.generate_perlin();
                    out << "New map generated.\n";
                    break;
                }
                redraw();
                break;
              default:
                return 0;
            }
            break;
        case GS_QUIT:
            SDL_Quit();
            exit(0);
        default:
            exit(9001);
    }
}

void Game::redraw()
{
    dsp.draw_map(0, 0, &M, P.getX()-12, P.getY()-12, 25, 25);
    dsp.draw_sprite(12*24, 12*24, P_sprite, P_spritestate);
    out.draw_to(&dsp);
    dsp.update();
}

int main(int argc, char *argv[])
{
    // seed random with processor ticks, pseudorandom enough
    srand(SDL_GetTicks());

    // Initialize game engine
    Game G;

    // Poll for events, and handle the ones we care about.
    SDL_Event event;
    bool loop = true;
    while(loop)
    {
        while (SDL_PollEvent(&event))
        {
            int status = G.handle_event(event);
            if(status == 1) loop = false;
        }
        SDL_Delay(1000/30);
    }
    return 0;
}
