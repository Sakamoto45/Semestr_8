#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>

// #include <ctime>
// #include <cstdlib>
// // #include <random>

using ll = long long;

using namespace std;

int solve()
{
    map<ll, vector<int>> cat;

    ll n;
    cin >> n;

    ll tmp_p, tmp_c;
    for (ll i = 0; i < n; i++)
    {
        cin >> tmp_p >> tmp_c;
        cat[tmp_c].push_back(tmp_p);
    }

    int max_count = 0;
    int count_max_count = 0;
    for (auto c : cat)
    {
        if (c.second.size() > max_count)
        {
            max_count = c.second.size();
            count_max_count = 0;
        }
        if (c.second.size() == max_count)
        {
            count_max_count++;
        }
    }

    vector<ll> result;

    // priority = -(cat_count * 2n + (n- last_pos))
    map<ll, ll> main_queue;
    int i = 1;
    for (auto c : cat)
    {
        main_queue[-(c.second.size() * 2 * n + 2 * n - (i++))] = c.first;
    }

    // 15 234 15 234 15 234 15

    // que
    queue<pair<ll, ll>> sub_queue;

    ll dist = (max_count == 1 ? 0 : (n - count_max_count) / (max_count - 1));

    while (!main_queue.empty())
    {
        result.push_back(main_queue.begin()->second);
        ll priority = main_queue.begin()->first;
        ll count = (-priority) / (2 * n);
        // ll last_p = n - (-priority) % (2 * n);
        // if (priority)
        if (count > 1)
            sub_queue.push({-((count - 1) * 2 * n + n - result.size()), result.back()});
        main_queue.erase(main_queue.begin());

        if (!sub_queue.empty() && result.size() + 1 - (n - (-sub_queue.front().first) % (2 * n)) >= dist)
        {
            main_queue.emplace(sub_queue.front());
            sub_queue.pop();
        }
    }

    for (auto r : result)
    {
        cout << cat[r][cat[r].size() - 1] << " ";
        cat[r].resize(cat[r].size() - 1);
    }
    cout << endl;

    return 0;
}

int main()
{

    // std::srand(std::time(nullptr));

    solve();
    // while (!solve())
    // {
    // }
    return 0;
}
