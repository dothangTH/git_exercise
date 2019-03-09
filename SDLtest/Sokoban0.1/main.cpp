#include <iostream>
#include <conio.h>
#include <SDL.h>
//#include <draw.h>
//#include <move.h>
#define KEYB_ESC 27
#define KEYB_UP 72
#define KEYB_RIGHT 77
#define KEYB_LEFT 75
#define KEYB_DOWN 80

using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const string WINDOW_TITLE = "An Implementation of Code.org Painter";
SDL_Window* window;
SDL_Renderer* renderer;

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal = false);
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);

bool valid(int WIDTH,int HEIGHT, char direction, int x, int y)
{
    switch (direction) {
    case 72:
        if (y >= 0) return true;
        else return false;
        break;
    case 75:
        if (x >= 0) return true;
        else return false;
        break;
    case 77:
        if (x < (WIDTH-100)) return true;
        else return false;
        break;
    case 80:
        if (y < (HEIGHT - 100)) return true;
        else return false;
        break;
    }
}




void Nextmove(char direction,int &a, int &b){
    SDL_Rect background;
    background.x = 0;
    background.y = 0;
    background.w = 800;
    background.h = 600;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &background);
    switch(direction) {
    case 72:
        b -= 100;
        break;
    case 75:
        a -= 100;
        break;
    case 77:
        a += 100;
        break;
    case 80:
        b += 100;
        break;
    case ' ':
        a = 300;
        b = 300;
        break;
    }
    SDL_Rect character;
    character.x = a;
    character.y = b;
    character.w = 100;
    character.h = 100;
    SDL_SetRenderDrawColor(renderer, 0, 20, 20, 100);
    SDL_RenderFillRect(renderer, &character);
    SDL_RenderPresent(renderer);
    return;
}




int main(int argc, char* argv[])
{
    char direction = ' ';
    int x=300,y=300;
    initSDL(window, renderer);
    while (direction != 27) {
            direction = getch();
            if (valid(800,600,direction,x,y)) Nextmove(direction, x, y);
    }
    quitSDL(window,renderer);
    return 0;
}

void logSDLError(std::ostream& os,
                 const std::string &msg, bool fatal)
{
    os << msg << " Error: " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}
void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        logSDLError(std::cout, "SDL_Init", true);

    window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) logSDLError(std::cout, "CreateWindow", true);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC);
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


