#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    // int n = 1e9
    int a, b, c, d;
    a = rnd.next(1, n);
    b = rnd.next(1, n);
    c = rnd.next(1, n);
    d = rnd.next(1, n);
    cout << a << " " << b << " " << c << " " << d << endl;
}