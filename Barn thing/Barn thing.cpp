// Barn thing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int MAX = 1001;
int paint[MAX][MAX];

int main() {
    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // Paint every cell in the rectangle
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                paint[x][y]++;
            }
        }
    }

    // Count cells with exactly K coats
    int area = 0;
    for (int x = 0; x < MAX; x++) {
        for (int y = 0; y < MAX; y++) {
            if (paint[x][y] == K) {
                area++;
            }
        }
    }

    cout << area << endl;
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
