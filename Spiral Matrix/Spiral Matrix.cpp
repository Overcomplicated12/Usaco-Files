// Spiral Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> matrix(M, vector<int>(N));
    vector<vector<bool>> visited(M, vector<bool>(N, false));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int dir = 0; // 0 = right, 1 = down, 2 = left, 3 = up
    int count = 0;
    int x = 0, y = 0; // start at top-left

    while (count < M * N) {
        cout << matrix[y][x] << " ";
        visited[y][x] = true;
        count++;

        // try to move in current direction
        int x1 = x, y1 = y;
        if (dir == 0) x1++;
        else if (dir == 1) y1++;
        else if (dir == 2) x1--;
        else y1--;

        // if out of bounds or already visited, turn right
        if (y1 < 0 || y1 >= M || x1 < 0 || x1 >= N || visited[y1][x1]) {
            dir = (dir + 1) % 4;
            if (dir == 0) x1 = x + 1, y1 = y;
            else if (dir == 1) y1 = y + 1, x1 = x;
            else if (dir == 2) x1 = x - 1, y1 = y;
            else y1 = y - 1, x1 = x;
        }

        x = x1;
        y = y1;
    }
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
