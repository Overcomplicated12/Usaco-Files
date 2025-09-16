// reflection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
using namespace std;

int N, U;
vector<string> canvas;

// Helper function to compute the minimum operations for a group of 4 symmetric cells
int group_cost(int r, int c) {
    vector<pair<int, int>> cells = {
        {r, c},
        {N - 1 - r, c},
        {r, N - 1 - c},
        {N - 1 - r, N - 1 - c}
    };
    int hash = 0, dot = 0;
    for (auto [x, y] : cells) {
        if (canvas[x][y] == '#') hash++;
        else dot++;
    }
    return min(hash, dot);
}

// Compute initial total moves for the whole canvas
int scan() {
    int moves = 0;
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            moves += group_cost(i, j);
        }
    }
    return moves;
}

int main() {
    cin >> N >> U;
    canvas.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> canvas[i];
    }

    vector<int> r(U), c(U);
    for (int i = 0; i < U; i++) {
        cin >> r[i] >> c[i];
        r[i]--;  // convert to 0-based
        c[i]--;
    }

    int moves = scan();
    cout << moves << "\n";

    for (int i = 0; i < U; i++) {
        int r0 = r[i];
        int c0 = c[i];

        // Subtract old contribution of the affected group
        moves -= group_cost(r0, c0);

        // Toggle the cell
        canvas[r0][c0] = (canvas[r0][c0] == '#' ? '.' : '#');

        // Add new contribution of the affected group
        moves += group_cost(r0, c0);

        cout << moves << "\n";
    }

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
