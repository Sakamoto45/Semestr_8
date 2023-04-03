#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    // int n = 1e9
    int w, h, l;
    w = rnd.next(1, n);
    h = rnd.next(1, n);
    l = rnd.next(1, n);
    cout << w << " " << h << " " << l << endl;
    cout << rnd.next(1, w) << " ";
    cout << rnd.next(1, h) << " ";
    cout << rnd.next(1, l) << endl;
}