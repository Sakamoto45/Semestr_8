#include "testlib.h"
#include <iostream>

#include <vector>

typedef long long ll;

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = atoi(argv[1]);
    int k = atoi(argv[2]);
    float p = atof(argv[3]);

    // n = rnd.next(2, n);
    // edges
    int m = 0;
    vector<vector<bool>> connected(n, vector<bool>(n, false));
    vector<vector<ll>> start(n, vector<ll>(n, 0));
    vector<vector<ll>> period(n, vector<ll>(n, 0));
    vector<vector<ll>> length(n, vector<ll>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // no 1 len loops
            if (i == j)
                continue;
            // skip edge with prob 1-p
            if (rnd.next(1.0) > p)
                continue;
            // generate edge
            m++;
            connected[i][j] = true;
            start[i][j] = rnd.next(1, k);
            period[i][j] = rnd.next(1, k);
            length[i][j] = rnd.next(1, k);
        }
    }

    cout << n << " " << m << " " << rnd.next(1, n) << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (connected[i][j])
                cout << i + 1 << " "
                     << j + 1 << " "
                     << start[i][j] << " "
                     << period[i][j] << " "
                     << length[i][j] << endl;
        }
    }
}