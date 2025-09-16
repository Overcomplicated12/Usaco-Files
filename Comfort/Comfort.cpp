// Comfort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int MAX = 1001;
bool grid[MAX][MAX] = { false };
int neighborCount[MAX][MAX] = { 0 };

int comfortableCount = 0;

// Directions: up, down, left, right
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// Check if cow at (x, y) is comfortable
bool isComfortable(int x, int y) {
    return grid[x][y] && neighborCount[x][y] == 3;
}

void updateNeighbor(int x, int y, int delta) {
    if (x < 0 || x >= MAX || y < 0 || y >= MAX) return;
    if (grid[x][y]) {
        if (neighborCount[x][y] == 3) comfortableCount--;
        neighborCount[x][y] += delta;
        if (neighborCount[x][y] == 3) comfortableCount++;
    }
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;

        grid[x][y] = true;

        // Count neighbors and update neighbors
        int count = 0;
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) {
                if (grid[nx][ny]) count++;
                updateNeighbor(nx, ny, 1);
            }
        }

        neighborCount[x][y] = count;
        if (count == 3) comfortableCount++;

        cout << comfortableCount << '\n';
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
