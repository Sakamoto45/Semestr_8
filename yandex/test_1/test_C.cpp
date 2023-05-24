#include <iostream>

#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    int g_a, g_b;
    cin >> n >> m;

    vector<int> score_v(n, 0);
    // multiset<int> score_s(score_v.begin(), score_v.end());
    map<int, int> score_m;
    score_m[0] = n;
    vector<int> p(10);
    int better = 0;

    for (int game = 0; game < m; game++)
    {

        cin >> g_a >> g_b;
        int diff = g_a - g_b;
        for (int i = 0; i < 10; i++)
        {
            cin >> p[i];
        }

        if (diff != 0)
        {
            for (int i = 0; i < 10; i++)
            {
                if (i == 5)
                {
                    diff *= -1;
                }
                if (p[i] == 0)
                {
                    if (diff > 0)
                    {
                        for (int j = 1; j <= diff; j++)
                        {
                            better -= score_m[++score_v[0]];
                        }
                    }
                    else
                    {
                        for (int j = 0; j < -diff; j++)
                        {
                            better += score_m[score_v[0]--];
                        }
                    }
                }
                else
                {
                    int old_score = score_v[p[i]];
                    int new_score = score_v[p[i]] += diff;

                    score_m[old_score]--;
                    score_m[new_score]++;

                    if (old_score <= score_v[0] && new_score > score_v[0])
                    {
                        better++;
                    }
                    else if (old_score > score_v[0] && new_score <= score_v[0])
                    {
                        better--;
                    }
                }
            }
        }

        cout << better << endl;
    }

    return 0;
}