void Nextmove(SDL_Window* &window, SDL_renderer* &renderer,char direction,int &a, int &b){
    SDL_RenderClear(renderer);
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
    case default:
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


