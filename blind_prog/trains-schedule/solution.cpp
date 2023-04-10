#include <iostream>

#include <vector>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<bool>> connected(n, vector<bool>(n, false));
    vector<vector<ll>> start(n, vector<ll>(n, 0));
    vector<vector<ll>> period(n, vector<ll>(n, 0));
    vector<vector<ll>> length(n, vector<ll>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        connected[u][v] = true;
        cin >> start[u][v] >> period[u][v] >> length[u][v];
    }

    vector<ll> result(n, INT64_MAX);
    result[s] = 0;
    vector<bool> checked(n, false);

    while (true)
    {
        int i = -1;
        for (int j = 0; j < n; j++)
        {
            if (!checked[j] && (i == -1 || result[j] < result[i]))
                i = j;
        }
        if (i == -1)
            break;
        if (result[i] == INT64_MAX)
            break;
        checked[i] = true;

        for (int j = 0; j < n; j++)
        {
            if (!connected[i][j])
                continue;
            ll new_time = start[i][j] + max(ll(0), (result[i] - start[i][j] - 1) / period[i][j] + 1) * period[i][j] + length[i][j];
            result[j] = min(result[j], new_time);
        }
    }

    for (auto it : result)
    {
        cout << (it == INT64_MAX ? -1 : it) << endl;
    }
}