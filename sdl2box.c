#include <SDL2/SDL.h>

int main (int argc, char** argv)
{
    SDL_Window* window = NULL;
    window = SDL_CreateWindow
    (
        "sdl2box", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = NULL;
    renderer =  SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED);

    // background black
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );

    SDL_Rect r;
    r.x = 20;
    r.y = 20;
    r.w = 600;
    r.h = 440;

    // blue rect
    SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
    SDL_RenderDrawRect( renderer, &r );
    // go..
    SDL_RenderPresent(renderer);

    // Wait for 10 sec
    SDL_Delay( 10000 );

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

