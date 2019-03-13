#include <iostream>
#include <conio.h>
#include <vector>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



using namespace std;
using namespace this_thread;
using namespace chrono;

const int Play_ground_size = 5;

bool deadlock(int x, int y) {
    if ((x == Play_ground_size-1) && (y == 0)) return true;
    if ((x == 0) && (y == Play_ground_size-1)) return true;
    if ((x == 0) && (y == 0)) return true;
    if ((x == Play_ground_size-1) && (y == Play_ground_size-1)) return true;
    return false;
}

bool box_ahead(vector<vector<char>> grid, char c, int x, int y) {
    switch (c) {
        case 72:
            if (grid[x-1][y] == 'B') return true;
            else return false;
            break;
        case 75:
            if (grid[x][y-1] == 'B') return true;
            else return false;
            break;
        case 77:
            if (grid[x][y+1] == 'B') return true;
            else return false;
            break;
        case 80:
            if (grid[x+1][y] == 'B') return true;
            else return false;
            break;
    }
}

bool valid_move(char c, int x, int y) {
    switch (c) {
        case 72:
            if (x>0) return true;
            else return false;
            break;
        case 75:
            if (y>0) return true;
            else return false;
            break;
        case 77:
            if (y < (Play_ground_size - 1)) return true;
            else return false;
            break;
        case 80:
            if (x < (Play_ground_size - 1)) return true;
            else return false;
            break;
    }
}

int main()
{
    char readkey = ' ';
    srand(time(0));
    vector <vector<char>> grid(5, vector<char> (5,'.'));
    int x, y, box_x, box_y;
    x = rand() % 5 + 0;
    y = rand() % 5 + 0;
    do{
        box_x = rand() % 3 + 1;
        box_y = rand() % 3 + 1;
    } while ((box_x == x) && (box_y == y));
    grid[x][y] = '0';
    grid[box_x][box_y] = 'B';
    while (readkey != 27) {
        for(int i = 0; i < Play_ground_size; i++) {
            for (int j=0; j < Play_ground_size; j++) cout << grid[i][j] << ' ';
            cout << endl;
        }
        readkey = getch();
        if(valid_move(readkey,x,y)) {
            if (!box_ahead(grid,readkey,x,y)) {
                grid[x][y] = '.';
                switch (readkey) {
                    case 72:
                        grid[x-1][y] = '^';
                        x -= 1;
                        break;
                    case 75:
                        grid[x][y-1] = '<';
                        y -= 1;
                        break;
                    case 77:
                        grid[x][y+1] = '>';
                        y += 1;
                        break;
                    case 80:
                        grid[x+1][y] = 'v';
                        x += 1;
                        break;
                }
            }
            else {
                if (valid_move(readkey, box_x,box_y)){
                    grid[x][y] = '.';
                    switch (readkey) {
                        case 72:
                            grid[x-1][y] = '^';
                            grid[box_x-1][box_y] = 'B';
                            x -= 1;
                            box_x -= 1;
                            break;
                        case 75:
                            grid[x][y-1] = '<';
                            grid[box_x][box_y - 1] = 'B';
                            y -= 1;
                            box_y -= 1;
                            break;
                        case 77:
                            grid[x][y+1] = '>';
                            grid[box_x][box_y+1] = 'B';
                            y += 1;
                            box_y += 1;
                            break;
                        case 80:
                            grid[x+1][y] = 'v';
                            grid[box_x+1][box_y] = 'B';
                            x += 1;
                            box_x += 1;
                            break;
                    }
                } else {
                    grid[box_x][box_y] = 'B';
                }
            }
        }
        //else grid[x][y] = '0';
        //sleep_for(milliseconds(50));
        switch (readkey) {
            case 72:
                grid[x][y] = '^';
                break;
            case 75:
                grid[x][y] = '<';
                break;
            case 77:
                grid[x][y] = '>';
                break;
            case 80:
                grid[x][y] = 'v';
                break;
        }
        if (deadlock(box_x,box_y)) {
            system("cls");
            for(int i = 0; i < Play_ground_size; i++) {
                for (int j=0; j < Play_ground_size; j++) cout << grid[i][j] << ' ';
                cout << endl;
            }
            cout << "DEADLOCK";
            return 0;
        }
        system("cls");
    }
    cout << "You pressed ESC";
    return 0;
}
