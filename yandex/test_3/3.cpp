#include <iostream>
#include <string>
#include <vector>

using namespace std;

double calc(vector<double> cost, vector<vector<int>> &vv, vector<double> &disc, int mask)
{
    for (int i = 0; mask; i++, mask >>= 1)
    {
        if (mask & 1)
        {
            for (auto c : vv[i])
            {
                cost[c] *= disc[i];
            }
        }
    }

    double result = 0;
    for (auto c : cost)
    {
        result += c;
    }
    return result;
}

int count_bits(int n)
{
    int result = 0;
    for (; n; n >>= 1)
    {
        result += (n & 1);
    }
    return result;
}

int main()
{
    int n, m, k;

    cin >> n >> m >> k;

    vector<double> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    int c, tmp;
    vector<vector<int>> vv(m);
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        for (int j = 0; j < c; j++)
        {
            cin >> tmp;
            vv[tmp - 1].push_back(i);
        }
    }

    vector<double> disc(m);
    for (int i = 0; i < m; i++)
    {
        cin >> disc[i];
        disc[i] = 1 - disc[i] / 100;
    }

    int best_mask = 0;
    double best_cost = 1e50;

    double tmp_d;

    for (int mask = 0; mask < (1 << m); mask++)
    {
        if (count_bits(mask) > k)
            continue;
        tmp_d = calc(cost, vv, disc, mask);
        if (best_cost > tmp_d)
        {
            best_cost = tmp_d;
            best_mask = mask;
        }
    }

    // cout << best_mask << endl;
    cout << count_bits(best_mask) << endl;

    for (int i = 1; best_mask; i++, best_mask >>= 1)
    {
        if (best_mask & 1)
            cout << i << " ";
    }

    // int count = 0;

    // for (auto c : cost)
    // {
    //     cout << c;
    // }

    return 0;
}
