#include <iostream>
using namespace std;

int strlen(const char a[]){
    int i=0;
    while (a[i] != '\0') i++;
    return i;
}
char* reverse(const char a[]) {
    char* s = new char[strlen(a)+1];
    for (int i = 0; i < strlen(a); i++) s[i] = a[strlen(a) - 1 - i];
    s[strlen(a)] = '\0';
    return s;
}
char* delete_char(const char a[],char c) {
    char* s = new char[strlen(a)+1];
    int count = 0;
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] != c) {
            s[count] = a[i];
            count ++;
        }
    }
    s[count] = '\0';
    return s;
}
char* pad_right(const char a[], int n) {
    int pad = n - strlen(a);
    if (pad < 0) pad = 0;
    char* s = new char[strlen(a) + pad + 1];
    for (int i=0; i<(strlen(a) + pad); i++) {
        if (i < strlen(a)) s[i] = a[i];
        else s[i] = '*';
    }
    s[strlen(a)+pad] = '\0';
    return s;
}
char* pad_left(const char a[], int n) {
    int pad = n - strlen(a);
    if (pad < 0) pad = 0;
    char* s = new char[strlen(a) + pad + 1];
    for (int i=0; i<(strlen(a) + pad); i++) {
        if (i<pad) s[i] = '*';
        else s[i] = a[i-pad];
    }
    s[strlen(a)+pad] = '\0';
    return s;
}
char* truncate(const char a[], int n) {
    char* s = new char[n+1];
    for (int i=0; i<n; i++) s[i] = a[i];
    s[n] = '\0';
    return s;
}
char* trim_left(const char a[]) {
    int count=0;
    while (a[count] == ' ') count++;
    char* s = new char[strlen(a) - count + 1];
    for (int i=count; i< strlen(a); i++) s[i-count] = a[i];
    s[strlen(a)-count] = '\0';
    return s;
}
char* trim_right(const char a[]) {
    int count=0;
    while (a[strlen(a)-count] == ' ') count++;
    char* s = new char[strlen(a) - count + 1];
    for (int i=0; i< (strlen(a)-count); i++) s[i] = a[i];
    s[strlen(a)-count] = '\0';
    return s;
}
bool is_palindrome(const char a[]) {
    for(int i=0; i<(strlen(a)/2); i++)
        if (a[i] != a[strlen(a)-i]) {
            return false;
    }
    return true;
}
int main()
{
    const char a[] = "       K63 CACLC 2      ";
    cout << reverse(a) << endl << delete_char(a,'C') << endl << pad_right(a,50) << endl << pad_left(a,50) << endl
         << truncate(a,2000) << endl << trim_left(a) << endl << trim_right(a) << endl;
    return 1;
}
