// Balloons.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
    int n; cin >> n;
    vector<pair<int, int>> balloons;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        balloons.push_back({l, r });
    }

    sort(balloons.begin(), balloons.end());

    int ans = 1;
    int curL = balloons[0].first;
    int curR = balloons[0].second;

    for (int i = 1; i < n; i++)
    {
        int l = balloons[i].first;
        int r = balloons[i].second;

        if (l <= curR)
        {
            curL = max(curL, l);
            curR = min(curR, r);
        }
        else
        {
            ans++;
            curL = l;
            curR = r;
        }
    }

    cout << ans << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
