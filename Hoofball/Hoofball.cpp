// Hoofball.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);


    int N;
    cin >> N;
    vector<int> x(N);

    for (int i = 0; i < N; i++) cin >> x[i];

    sort(x.begin(), x.end());

    vector<int> to(N, -1), indeg(N, 0);
    for (int i = 0; i < N; i++)
    {
        if (i == 0) to[i] = 1;
        else if (i == N - 1) to[i] = N - 2;
        else
        {
            int dl = x[i] - x[i - 1];
            int dr = x[i + 1] - x[i];
            to[i] = (dl <= dr) ? i - 1 : i + 1;
        }
        indeg[to[i]]++;
    }


    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        if (indeg[i] == 0) ans++;
    }

    for (int i = 0; i + 1 < N; i++)
    {
        if (to[i] == i + 1 and to[i + 1] == i)
        {
            if (indeg[i] == 1 and indeg[i + 1] == 1) ans++;
        }
    }

    cout << ans << endl;
    return 0;
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
