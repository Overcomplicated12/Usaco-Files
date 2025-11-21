// TheGreatRevegetation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> g(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> color(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        bool used[5] = { false };
        for (int a : g[i])
        {
            if (color[a] != 0)
            {
                used[color[a]] = true;
            }
        }
        for (int c = 1; c <= 4; c++) {
            if (!used[c]) {
                color[i] = c;
                break;
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << color[i];
    }
    cout << endl;
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
