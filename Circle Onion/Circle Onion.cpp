// Circle Onion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;

    // Arrays to store circle data
    int cx[100], cy[100], r[100];

    for (int i = 0; i < N; ++i) {
        cin >> cx[i] >> cy[i] >> r[i];
    }

    set<pair<int, int>> covered_points;

    for (int i = 0; i < N; ++i) {
        int x0 = cx[i];
        int y0 = cy[i];
        int radius = r[i];
        int r_squared = radius * radius;

        // Loop through bounding box of the circle
        for (int x = x0 - radius; x <= x0 + radius; ++x) {
            for (int y = y0 - radius; y <= y0 + radius; ++y) {
                int dx = x - x0;
                int dy = y - y0;
                if (dx * dx + dy * dy <= r_squared) {
                    covered_points.insert({ x, y });
                }
            }
        }
    }

    cout << covered_points.size() << endl;
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
