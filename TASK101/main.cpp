#include <SDL.h>
#include <stdio.h>
#include <math.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

int CX = SCREEN_WIDTH / 2;
int CY = SCREEN_WIDTH / 2;
int rad = 200;

bool initializeSDL(SDL_Window** window, SDL_Renderer** renderer)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("ERROR INITIALIZING SDL!");

        return false;
    }

    *window = SDL_CreateWindow("ORNY_NABILA", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (*window == NULL)
    {
        printf("ERROR INITIALIZING SDL!");

        return false;
    }

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if (*renderer == 0)
    {
        printf("ERROR INITIALIZING RENDERER!");

        return false;
    }

    return true;
}

void Drawing_Circle(SDL_Renderer* renderer, int centerX, int centerY, int radius)
{
    for (int x = -radius; x <= radius; x++)
    {
        for (int y = -radius; y <= radius; y++)
        {
            if (x * x + y * y <= radius * radius)
            {
                SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            }
        }
    }
}

int main(int argc, char* argv[])
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (!initializeSDL(&window, &renderer))
    {
        return 1;
    }

    SDL_Event event;

    bool game = true;

    while (game)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                game = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 100, 200, 200, 100);
        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        Drawing_Circle(renderer, CX, CY, rad);

        SDL_RenderPresent(renderer);
    }

    return 0;
}