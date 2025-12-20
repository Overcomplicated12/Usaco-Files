// Unguarded Cells.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, G, W;
    cin >> M >> N >> G >> W;

    // 0 = empty, 1 = guard, 2 = wall
    vector<vector<int>> state(M, vector<int>(N, 0));
    vector<vector<bool>> seen(M, vector<bool>(N, false));

    // Read guards
    for (int i = 0; i < G; i++) {
        int r, c;
        cin >> r >> c;
        state[r][c] = 1;
    }

    // Read walls
    for (int i = 0; i < W; i++) {
        int r, c;
        cin >> r >> c;
        state[r][c] = 2;
    }

    // Sweep left → right
    for (int r = 0; r < M; r++) {
        bool active = false;
        for (int c = 0; c < N; c++) {
            if (state[r][c] == 2) active = false;
            else if (state[r][c] == 1) active = true;
            else if (active) seen[r][c] = true;
        }
    }

    // Sweep right → left
    for (int r = 0; r < M; r++) {
        bool active = false;
        for (int c = N - 1; c >= 0; c--) {
            if (state[r][c] == 2) active = false;
            else if (state[r][c] == 1) active = true;
            else if (active) seen[r][c] = true;
        }
    }

    // Sweep top → bottom
    for (int c = 0; c < N; c++) {
        bool active = false;
        for (int r = 0; r < M; r++) {
            if (state[r][c] == 2) active = false;
            else if (state[r][c] == 1) active = true;
            else if (active) seen[r][c] = true;
        }
    }

    // Sweep bottom → top
    for (int c = 0; c < N; c++) {
        bool active = false;
        for (int r = M - 1; r >= 0; r--) {
            if (state[r][c] == 2) active = false;
            else if (state[r][c] == 1) active = true;
            else if (active) seen[r][c] = true;
        }
    }

    // Count unguarded empty cells
    int answer = 0;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            if (state[r][c] == 0 && !seen[r][c]) {
                answer++;
            }
        }
    }

    cout << answer << "\n";
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
