#include <iostream>
#include <chrono>
#include <conio.h>
#include <thread>
#define KEYB_UP 72
#define KEYB_DOWN 80
#define KEYB_LEFT 75
#define KEYB_RIGHT 77
#define KEYB_ESC 27

using namespace std;

int main()
{
    char c=' ';
    while (c != 27) {
        c = getch();
        system("cls");
        switch (c){
        case 72 :
            cout << "You pressed up arrow.";
            break;
        case 80 :
            cout << "You pressed down arrow.";
            break;
        case 75 :
            cout << "You pressed left arrow.";
            break;
        case 77 :
            cout << "You pressed right arrow.";
            break;
        }
    }
    cout << "You pressed ESC. Bye!";
    //this_thread :: sleep_for(chrono :: seconds(2));
    return 0;
}
