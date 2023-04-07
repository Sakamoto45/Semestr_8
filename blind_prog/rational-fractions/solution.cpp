#include <iostream>
#include <numeric>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll p = 0, q = 1;
    ll a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        ll tmp_p = p * b + a * q;
        ll tmp_q = q * b;
        ll gcd_pq = gcd(tmp_p, tmp_q);
        p = tmp_p / gcd_pq;
        q = tmp_q / gcd_pq;
    }
    cout << p << " " << q << endl;
}