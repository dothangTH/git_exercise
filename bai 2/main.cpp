#include <iostream>

using namespace std;

long factorial(int x) {
    cout << "x = " << x << " at " << &x << endl;
    if (x <= 1) return 1;
    else return factorial(x-1)*x;
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}
