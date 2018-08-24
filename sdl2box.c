#include <SDL2/SDL.h>
#include <time.h>

#define RUNS 10000

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

    SDL_Rect r;
    r.x = 20;
    r.y = 20;
    r.w = 600;
    r.h = 440;

    struct timespec start;
    clock_gettime(CLOCK_REALTIME, &start);

    for (int i=0; i<RUNS; i++)
	{
        // background black
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
        SDL_RenderClear( renderer );
        // blue rect
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        SDL_RenderDrawRect( renderer, &r );
        // green vertical
        SDL_SetRenderDrawColor( renderer, 0, 255, 0, 255 );
        SDL_RenderDrawLine(renderer, 320, 40, 320, 440);
        // red horizontal
        SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
        SDL_RenderDrawLine(renderer, 40, 240, 600, 240);
        // go..
        SDL_RenderPresent(renderer);
    }

    struct timespec end;
    clock_gettime(CLOCK_REALTIME, &end);
    int t_ms = (end.tv_sec - start.tv_sec) * 1000 +
               (end.tv_nsec - start.tv_nsec) / 1000000;
    printf("Took %ims\n", t_ms);
    double timePerRunMs = ((double)t_ms) / ((double)RUNS);
    printf("One frame took %.3fms\n", timePerRunMs);

    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

