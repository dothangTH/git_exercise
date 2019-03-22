#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

void run(int &position, int step) {
    position += step;
    if (position < 0) position = 0;
    return;
}

int generate_turtle_move() {
    int result = rand() % 10 + 1;
    if (result <= 5) return 3;
    else if (result > 8) return -6;
    else return 1;
}

int generate_rabit_move() {
    int result = rand() % 10 + 1;
    if (result <= 2) return 0;
    else if (result > 8) return -2;
    else if (result <= 4) return 9;
    else if (result > 5) return 1;
    else return -12;
}

int main()
{
    int Rabit=0,Turtle=0;
    srand(time(0));
    int step;
    cout << "START" << endl;
    cout << "Turtle: " << Turtle << "   Rabit: " << Rabit << endl;
    while ((Rabit < 70) && (Turtle < 70)) {
        step = generate_turtle_move();
        run(Turtle, step);
        step = generate_rabit_move();
        run(Rabit, step);
        cout << "Turtle: " << Turtle << "   Rabit: " << Rabit << endl;
    }
    cout << "FINISH" << endl;
    if ((Rabit >= 70) && (Turtle < 70)) cout << "Rabit win the race.";
    else if ((Rabit < 70) && (Turtle >= 70)) cout << "Turtle win the race.";
    else cout << "It's a draw.";
    return 0;
}
