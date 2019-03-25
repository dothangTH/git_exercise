#include<vector>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#include<SDL.h>
#include<stdio.h>

SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;
SDL_Surface* Playground = NULL;
SDL_Surface* Character = NULL;
SDL_Surface* Box = NULL;
SDL_Surface* Goal = NULL;

const int SCREEN_WIDTH = 450;
const int SCREEN_HEIGHT = 450;
const int WALL = 1;
const int BOX = 2;
const int SPACE = 3;

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "Moving test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Get window surface
			gSurface = SDL_GetWindowSurface( gWindow );
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load splash image
	Playground = SDL_LoadBMP( "playground.bmp" );
	if( Playground == NULL )
	{
		printf( "Unable to load playground %s! SDL Error: %s\n", "playground.bmp", SDL_GetError() );
		success = false;
	}

	Character = SDL_LoadBMP( "character.bmp" );
	if( Character == NULL )
	{
		printf( "Unable to load character %s! SDL Error: %s\n", "character.bmp", SDL_GetError() );
		success = false;
	}

	Box = SDL_LoadBMP("box.bmp");
	if( Box == NULL )
	{
		printf( "Unable to load box %s! SDL Error: %s\n", "box.bmp", SDL_GetError() );
		success = false;
	}

	Goal = SDL_LoadBMP("goal.bmp");
	if( Goal == NULL )
	{
		printf( "Unable to load goal %s! SDL Error: %s\n", "goal.bmp", SDL_GetError() );
		success = false;
	}

	return success;
}

void close()
{
	//Deallocate surface
	SDL_FreeSurface( Character );
	Character = NULL;

	SDL_FreeSurface( Box );
	Box = NULL;

	SDL_FreeSurface( Goal );
	Goal = NULL;

	SDL_FreeSurface( Playground );
	Playground = NULL;

	SDL_FreeSurface( gSurface );
	gSurface = NULL;

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

void Draw_the_move(int char_x, int char_y,int box_x, int box_y, int goal_x, int goal_y) {
    SDL_BlitSurface(Playground,NULL,gSurface,NULL);
    SDL_Rect goalRect;
    goalRect.x = goal_x*50;
    goalRect.y = goal_y*50;
    goalRect.w = 50;
    goalRect.h = 50;
    SDL_BlitScaled(Goal,NULL,gSurface,&goalRect);
    SDL_Rect charRect;
    charRect.x = char_x*50;
    charRect.y = char_y*50;
    charRect.w = 50;
    charRect.h = 50;
    SDL_BlitScaled(Character,NULL,gSurface,&charRect);
    SDL_Rect boxRect;
    boxRect.x = box_x*50;
    boxRect.y = box_y*50;
    boxRect.w = 50;
    boxRect.h = 50;
    SDL_BlitScaled(Box,NULL,gSurface,&boxRect);
    SDL_UpdateWindowSurface( gWindow );
    return;
}


bool valid_move(std::vector<std::vector<int>> grid, char direction, int y, int x) {
    switch (direction) {
        case 'u':
            if (grid[y-1][x] == SPACE) return true;
            break;
        case 'd':
            if (grid[y+1][x] == SPACE) return true;
            break;
        case 'l':
            if (grid[y][x-1] == SPACE) return true;
            break;
        case 'r':
            if (grid[y][x+1] == SPACE) return true;
            break;
    }
    return false;
}

void generate_playground(std::vector<std::vector<int>>& grid) {
    for(int i=0; i<9; i++) {
        grid[0][i] = WALL;
        grid[8][i] = WALL;
        grid[i][0] = WALL;
        grid[i][8] = WALL;
    }
    return;
}

void initialize_char_pos(int& x, int& y) {
    srand(time(0));
    x = rand() % 7 + 1;
    y = rand() % 7 + 1;
    return;
}

void initialize_box_pos(int& x, int& y, int box_x, int box_y){
    do {
        x = rand() % 5 + 2;
        y = rand() % 5 + 2;
    } while ((x == box_x) && (y == box_y));
    return;
}

void make_move(std::vector<std::vector<int>>& grid, char direction, int& x, int& y) {
    switch (direction) {
        case 'u':
            std::swap(grid[y-1][x],grid[y][x]);
            y-=1;
            break;
        case 'd':
            std::swap(grid[y+1][x],grid[y][x]);
            y+=1;
            break;
        case 'l':
            std::swap(grid[y][x-1],grid[y][x]);
            x-=1;
            break;
        case 'r':
            std::swap(grid[y][x+1],grid[y][x]);
            x+=1;
            break;
    }
    return;
}

bool box_ahead(std::vector<std::vector<int>> grid,char direction, int x, int y) {
    switch(direction) {
        case 'u':
            if (grid[y-1][x] == BOX) return true;
            break;
        case 'd':
            if (grid[y+1][x] == BOX) return true;
            break;
        case 'l':
            if (grid[y][x-1] == BOX) return true;
            break;
        case 'r':
            if (grid[y][x+1] == BOX) return true;
            break;
    }
    return false;
}
