#include <assert.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{

    double num;
    for (int i = 1; i < 100000000; i++)
    {
        num = 1.0 / i;
        cout << i << " " << num << " " << 1.0 / num << " " << fmod(1.0 / num, 1) << endl;
        // assert(fmod(1.0 / num, 1) == 0);
    }

    return 0;
}
