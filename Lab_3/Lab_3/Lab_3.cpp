#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    long double ln, y, y1, y2;
    int f,m,i;
    double d,x,fx,step;
    int n = 10;
    double e = 0.0001;

    step = (1 - 0.1) / 10;
    x = 0.1;

    while (x <= 1) {
        fx = pow(3, x);
        y2 = 0;
        y1 = 1;
        y = 1;
        f = 1;
        m = 1;
        d = x;
        i = 0;
        ln = log(3);

        while (abs(y1 - y2) > e) {
            y2 = y1;
            y1 = y1 + ln / f * d;
            f = f * (m + 1);
            m = m + 1;
            ln = ln * log(3);
            d = d * x;
        }
        f = 1;
        m = 1;
        d = x;
        ln = log(3);

        while (i < n) {
            y = y + ln / f * d;
            f = f * (m + 1);
            m = m + 1;
            ln = ln * log(3);
            d = d * x;
            i++;
        }
        cout << "X= " << x << " SN= " << y << " SE= " << y1 << " Y= " << fx << endl;
        x = x + step;
    }
}
