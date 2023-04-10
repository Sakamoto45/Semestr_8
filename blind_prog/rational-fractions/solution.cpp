#include <iostream>
#include <numeric>

using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c, d, p, q;
    cin >> a >> b >> c >> d;
    p = a * d + b * c;
    q = b * d;
    ll gcd_pq = gcd(p, q);
    cout << p / gcd_pq << " " << q / gcd_pq;
}