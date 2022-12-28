#include <iostream>
#include <math.h>

using namespace std;

// Перове задание
int Task_1_D() {
    double a, b, c, d, e, s;
    a = 1000;
    b = 0.0001;
    c = a + b;
    c = pow(c, 2);
    d = pow(a, 2);
    e = pow(b, 2);
    s = (c + (2 * a * b)) / e;
    cout << "Тип данных double: " << s << endl;
    return 0;
}

int Task_1_F() {
    float a, b, c, d, e, s;
    a = 1000;
    b = 0.0001;
    c = a + b;
    c = pow(c, 2);
    d = pow(a, 2);
    e = pow(b, 2);
    s = (c + (2 * a * b)) / e;
    cout << "Тип данных float: " << s << endl;
    return 0;
}

// Второе задание

int Task_2() {
    int n, m;
    n = 10;
    m = 10;
    cout << "n+++m " << (n++ + m) << endl;
    cout << "m-->n " << (m-- > n) << endl;
    cout << "n-->m " << (n-- > m) << endl;
    return 0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Task_1_F();
    Task_1_D();
    cout << endl;
    Task_2();
}

