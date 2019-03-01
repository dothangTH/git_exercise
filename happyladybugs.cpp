#include <iostream>
#include <map>

using namespace std;

void Ladybugs(map<char,int>& Bug_map) {
    int n;
    string s;
    bool empty = false;
    cin >> n >> s;
    map<char,int> :: iterator it;
    for (int i=0; i<n; i++) {
        if (s[i] == '_') {
            empty = true;
            continue;
        }
        it = Bug_map.find(s[i]);
        if (it == Bug_map.end()) Bug_map.insert(pair<char,int>(s[i],1));
        else it -> second++;
    }
    if (!empty) {
        for (int i = 0; i < n; i++)
        if ((s[i] != s[i+1]) && (s[i] != s[i-1])) {
            cout << "NO" << endl;
            Bug_map.clear();
            return;
        }
        cout << "YES" << endl;
        Bug_map.clear();
        return;
    }
    for (it = Bug_map.begin(); it != Bug_map.end(); it++)
    if (it -> second == 1) {
        cout << "NO" << endl;
        Bug_map.clear();
        return;
    }
    cout << "YES" << endl;
    Bug_map.clear();
    return;
}

int main()
{
    int g;
    map<char,int> Bug_map;
    cin >> g;
    for (int i=1; i<=g; i++) Ladybugs(Bug_map);
    return 0;
}
