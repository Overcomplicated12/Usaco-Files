// MowingTheField.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <climits>

using namespace std;

int main()
{
    // USACO input/output redirection
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int N;
    cin >> N;  // number of instructions

    // Direction vectors for movement
    // Each direction maps to (dx, dy) coordinate changes
    map<char, pair<int, int>> dir;
    dir['N'] = { 0, 1 };
    dir['S'] = { 0, -1 };
    dir['E'] = { 1, 0 };
    dir['W'] = { -1, 0 };

    // Map to record: position -> last time visited
    map<pair<int, int>, int> visited;

    // Start at (0,0) at time t = 0
    int x = 0, y = 0, t = 0;
    visited[{0, 0}] = 0;

    int best = INT_MAX;  // store smallest time difference

    // Process each movement instruction
    for (int i = 0; i < N; i++)
    {
        char D; // direction
        int S;  // number of steps
        cin >> D >> S;

        int dx = dir[D].first;
        int dy = dir[D].second;

        // Move step by step (one unit per time step)
        for (int j = 0; j < S; j++)
        {
            t++;       // increase time
            x += dx;   // update position
            y += dy;

            pair<int, int> pos = { x, y };

            // If this cell was visited before
            if (visited.count(pos)) {
                // calculate time since last visit
                best = min(best, t - visited[pos]);
            }

            // update last visit time
            visited[pos] = t;
        }
    }

    // If best was never updated, no re-visits occurred
    if (best == INT_MAX) cout << -1 << endl;
    else cout << best << endl;

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
