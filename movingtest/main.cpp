#include "myheader.h"
#include <iostream>

int main( int argc, char* args[] )
{
    std::vector<std::vector<int>> grid(9,std::vector<int>(9,SPACE));
    generate_playground(grid);

    int goal_x,goal_y;
    std::cin >> goal_x >> goal_y;

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;
			bool win = false;

			//Event handler
			SDL_Event e;

			int char_x,char_y,box_x,box_y;

			initialize_char_pos(char_x,char_y);

			initialize_box_pos(box_x,box_y,char_x,char_y);

			grid[box_y][box_x] = BOX;

			char direction;

            Draw_the_move(char_x,char_y,box_x,box_y,goal_x,goal_y);

			//While application is running
			while( (!quit) && (!win) )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT ) {
						quit = true;
					} else if( e.type == SDL_KEYDOWN ) {
						switch( e.key.keysym.sym )
						{
							case SDLK_UP:
							direction = 'u';
							Character = SDL_LoadBMP("characterup.bmp");
							break;

							case SDLK_DOWN:
							direction = 'd';
							Character = SDL_LoadBMP("characterdown.bmp");
							break;

							case SDLK_LEFT:
							direction = 'l';
							Character = SDL_LoadBMP("characterleft.bmp");
							break;

							case SDLK_RIGHT:
							direction = 'r';
							Character = SDL_LoadBMP("characterright.bmp");
							break;

							default:
                            direction = 'x';
                            break;
						}
						if (box_ahead(grid, direction, char_x, char_y)) {
                            if (valid_move(grid, direction, box_y, box_x)) {
                                make_move(grid, direction, box_x, box_y);
                                make_move(grid, direction, char_x, char_y);
                            }
						} else {
                            if (valid_move(grid,direction,char_y,char_x)) make_move(grid,direction,char_x,char_y);
						}
                        Draw_the_move(char_x,char_y,box_x,box_y,goal_x,goal_y);
					}
				}
				win = (grid[goal_y][goal_x] == BOX);
			}
		}
	}
	//Free resources and close SDL
	close();

    return 0;
}
