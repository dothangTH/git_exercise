#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void Missing_number(map <int,int> occur, vector<int> a, vector<int> b) {
    int n,m,x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int mark_a=0,mark_b=0;
    map<int,int> :: iterator it;
    while (n!=m) {
        if (a[mark_a] == b[mark_b]) {
            mark_a++;
            mark_b++;
        }
        else {
            it = occur.find(b[mark_b]);
            if (it == occur.end()){
                 cout << b[mark_b] <<' ';
                 occur.insert(pair<int,int>(b[mark_b],1));
            }
            mark_b++;
            m-=1;
        }
    }
    return;
}

int main()
{
    map<int,int> occur;
    vector<int> a,b;
    Missing_number(occur,a,b);
    return 0;
}
