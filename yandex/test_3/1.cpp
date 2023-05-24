#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string weekday;

    cin >> n >> weekday;

    int m;

    if (weekday == "Monday")
    {
        m = 0;
    }
    if (weekday == "Tuesday")
    {
        m = 1;
    }
    if (weekday == "Wednesday")
    {
        m = 2;
    }
    if (weekday == "Thursday")
    {
        m = 3;
    }
    if (weekday == "Friday")
    {
        m = 4;
    }
    if (weekday == "Saturday")
    {
        m = 5;
    }
    if (weekday == "Sunday")
    {
        m = 6;
    }

    for (int i = 0; i < m + n; i++)
    {
        if (i < m)
            cout << "..";
        else if (i - m + 1 < 10)
            cout << "." << i - m + 1;
        else
            cout << i - m + 1;
        if (i % 7 == 6 || i == m + n - 1)
            cout << "\n";
        else
            cout << " ";
    }

    return 0;
}
