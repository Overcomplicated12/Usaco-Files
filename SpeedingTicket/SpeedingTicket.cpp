#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> speedLimit(100);
    vector<int> bessieSpeed(100);

    int position = 0;

    // Fill in the speed limit for each mile
    for (int i = 0; i < n; i++)
    {
        int length, limit;
        cin >> length >> limit;

        for (int j = 0; j < length; j++)
        {
            speedLimit[position] = limit;
            position++;
        }
    }

    position = 0;

    // Fill in Bessie's speed for each mile
    for (int i = 0; i < m; i++)
    {
        int length, speed;
        cin >> length >> speed;

        for (int j = 0; j < length; j++)
        {
            bessieSpeed[position] = speed;
            position++;
        }
    }

    int maximumOver = 0;

    // Compare each mile
    for (int i = 0; i < 100; i++)
    {
        maximumOver = max(maximumOver,
            bessieSpeed[i] - speedLimit[i]);
    }

    cout << maximumOver << endl;

    return 0;
}