#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int roll_dice()
{
    return rand() % 6 + 1;
}

int main()
{
    int player_1=0,player_2=0,roll;
    srand(time(0));
    while (!((player_1 >= 100) || (player_2 >= 100))) {
        cout << "Player 1:" << player_1 << "    Player 2:" << player_2 << endl;
        if (player_1 > player_2) {
            roll = roll_dice();
            cout << "Player 2 roll " << roll << endl;
            player_2 += roll;
        }
        else {
            roll = roll_dice();
            cout << "Player 1 roll " << roll << endl;
            player_1 += roll;
        }
    }
    return 0;
}
