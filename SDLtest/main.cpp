#include <iostream>
#include <SDL.h>

using namespace std;

//void SDL_UpdateWindowSurface(SDL_Window *window);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}


const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    //window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       //SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateSoftwareRenderer(SDL_GetWindowSurface(window));
    if (renderer == nullptr) logSDLError(std::cout, "CreateRenderer", true);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
        if ( SDL_WaitEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
            return;
        SDL_Delay(100);
    }
}
int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    initSDL(window, renderer);

    // Your drawing code here
        SDL_RenderClear(renderer);

    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);   // white
    SDL_Rect filled_rect;
    filled_rect.x = 200;
    filled_rect.y = 200;
    filled_rect.w = 400;
    filled_rect.h = 400;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &filled_rect);
    SDL_Rect filled_rect1;
    filled_rect1.x = 250;
    filled_rect1.y = 250;
    filled_rect1.w = 300;
    filled_rect1.h = 300;
    SDL_SetRenderDrawColor(renderer, 0, 30, 70, 200);
    SDL_RenderFillRect(renderer, &filled_rect1);
    SDL_Rect filled_rect2;
    filled_rect2.x = 300;
    filled_rect2.y = 300;
    filled_rect2.w = 200;
    filled_rect2.h = 200;
    SDL_SetRenderDrawColor(renderer, 100, 0, 100, 0);
    SDL_RenderFillRect(renderer, &filled_rect2);
    SDL_Rect filled_rect3;
    filled_rect3.x = 350;
    filled_rect3.y = 350;
    filled_rect3.w = 100;
    filled_rect3.h = 100;
    SDL_SetRenderDrawColor(renderer, 0, 28, 32, 64);
    SDL_RenderFillRect(renderer, &filled_rect3);
    SDL_UpdateWindowSurface(window);
    // use SDL_RenderPresent(renderer) to show it

    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}

