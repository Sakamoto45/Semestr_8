#include <iostream>
#include <string>
#include <vector>
#include <map>

using ll = long long;

using namespace std;

int main()
{
    ll n;

    cin >> n;

    ll result = n;
    // vector<ll> prod(n);
    // vector<ll> cat(n);
    // prod, cat
    map<ll, ll> prod;
    vector<ll> order(n);

    ll tmp_p, tmp_c;
    for (ll i = 0; i < n; i++)
    {
        cin >> tmp_p >> tmp_c;
        prod[tmp_p] = tmp_c;
    }
    for (ll i = 0; i < n; i++)
    {
        cin >> order[i];
    }

    // category, last_pos of product
    map<ll, ll> last_pos;

    for (ll i = 0; i < n; i++)
    {
        ll cat = prod[order[i]];
        auto it = last_pos.find(cat);
        if (it != last_pos.end())
        {
            result = min(result, i - it->second);
        }
        last_pos[cat] = i;
    }
    cout << result << endl;

    return 0;
}
