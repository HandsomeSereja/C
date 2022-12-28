#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int k = 0;
    char x[5];
    setlocale(LC_ALL,"Russian");
    char s[255];
    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
    {
        if (s[i] == s[len-i-1]) {
            k = 1;
        }
        else {
            k = 0;
        }
    }
    if (k == 1) {
        cout << "Слово полиндром";
    }
    else {
        cout << "Слово не полиндром";
    }
}
    