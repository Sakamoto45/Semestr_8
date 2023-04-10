#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int p = a * d + b * c;
    int q = b * d;
    int p1 = p;
    int q1 = q;
    while (p1 != 0 && q1 != 0)
    {
        if (p1 > q1)
            p1 %= q1;
        else
            q1 %= p1;
    }
    p /= (p1 + q1);
    q /= (p1 + q1);
    cout << p << ' ' << q;
}