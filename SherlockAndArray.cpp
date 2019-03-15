#include <vector>
#include <iostream>

using namespace std;

void Sherlock_and_Array(vector<int> & arr, int n) {
    int sum_left = 0, sum_right = 0,  x;
    for (int i=0; i<n; i++) {
        cin >> x;
        sum_left += x;
        arr.push_back(x);
    }
    int j = n - 1;
    while (j >= 0) {\
        sum_left -= arr[j];
        if (sum_left == sum_right) {
            cout << "YES" << endl;
            return;
        }
        sum_right += arr[j];
        j--;
    }
    cout << "NO" << endl;
    return;
}

int main()
{
    int Case,n;
    vector <int> arr;
    cin >> Case;
    for (int i=0; i< Case; i++) {
        cin >> n;
        Sherlock_and_Array(arr,n);
        arr.clear();
    }
    return 0;
}
