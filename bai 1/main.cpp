#include <iostream>

using namespace std;

int main()
{
    int a[3];
    char b[3];
    char* p;
    cin >> a[0] >> a[1] >> a[2];
    cout << &a[0] << ' ' << &a[1] << ' ' << &a[2] << endl; // Dia chi cac phan tu lien tiep cach nhau 4 o nho
    for (int i=0; i<3; i++) {
        cin >> b[i];
        p = &b[i];
        cout << &p << ' '; // Dia chi cac phan tu giong nhau
    }
    return 0;
}
