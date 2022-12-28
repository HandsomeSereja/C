#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int i, s;
    s = 0;
    for (i = 0; i < 9; i++) {
        if ((i % 3) == 0) {
            s = s + i;
        }
    }
    cout << "Сумма: " << s << endl;
}
