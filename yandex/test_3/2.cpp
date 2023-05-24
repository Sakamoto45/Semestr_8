#include <iostream>
#include <vector>
#include <string>

using namespace std;

int foo(vector<vector<int>> &plane, int r, int s)
{
    int count = 0;
    if (s == 1 || s == 2)
        count += (plane[r][3] != -1);
    if (s == 1)
        count += (plane[r][2] != -1);
    if (s == 6 || s == 5)
        count += (plane[r][4] != -1);
    if (s == 6)
        count += (plane[r][5] != -1);

    switch (count)
    {
    case 0:
        return 0;
    case 1:
        return 5;
    case 2:
        return 15;
    }
}

int main()
{
    int n;
    string row_seat;

    cin >> n;

    vector<int> a(n);
    vector<int> row(n);
    vector<int> seat(n);
    vector<bool> come(n, false);

    // 1 2 3 0 4 5 6
    // A B C p D E F
    vector<vector<int>> plane(31, vector<int>(7, -1));

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> row_seat;
        row[i] = atoi(row_seat.substr(0, row_seat.length() - 1).c_str());
        seat[i] = row_seat[row_seat.length() - 1] - 'A' + 1;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << a[i] << " " << row[i] << " " << seat[i] << endl;
    // }

    int t = 0;
    int in = 0;
    bool done;
    do
    {
        done = true;
        t++;

        for (int r = 30; r > 0; r--)
        {
            int pas = plane[r][0];
            if (pas != -1)
            {
                done = false;
                if (row[pas] > r)
                {
                    if (plane[r + 1][0] == -1)
                    {
                        plane[r + 1][0] = plane[r][0];
                        plane[r][0] = -1;
                    }
                }
                else
                {
                    if (!come[pas])
                    {
                        a[pas] += foo(plane, row[pas], seat[pas]);
                        come[pas] = true;
                    }
                    if (a[pas] == 0)
                    {
                        plane[row[pas]][seat[pas]] = pas;
                        plane[r][0] = -1;
                    }
                    else
                    {
                        a[pas]--;
                    }
                }
            }
        }

        if (in < n && plane[1][0] == -1)
        {
            plane[1][0] = in;
            in++;
            done = false;
        }
    } while (!done);

    cout << t - 2 << endl;

    return 0;
}
