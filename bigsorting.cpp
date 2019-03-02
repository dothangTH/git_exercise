#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

void compare(string& a, string& b) {
    if (a.size() > b.size()) {
        swap(a,b);
        return;
    }
    if (a.size() < b.size()) return;
    for (int i=0; i<a.size(); i++) {
        if (a[i] > b[i]) {
            swap (a,b);
            return;
        }
        if (a[i] < b[i]) return;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<string> str_array(n);
    for (int i=0; i<n; i++) cin >> str_array[i];
    for (int i=0; i<(n-1); i++)
        for (int j=i+1; j<n; j++)
            compare(str_array[i],str_array[j]);
    for (int i=0; i<n; i++) cout << str_array[i] << ' ';
    return 0;
}
