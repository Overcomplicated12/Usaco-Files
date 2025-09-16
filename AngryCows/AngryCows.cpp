// AngryCows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Simulate explosions from a starting index in one direction
int explodeOneDirection(const vector<int>& pos, int startIndex, int direction) {
    int N = pos.size();
    int exploded = 1;
    int t = 1;
    int last = pos[startIndex];

    int i = startIndex;
    while (true) {
        int farthest = last;
        // Move in the specified direction, within radius t
        while (true) {
            int ni = i + direction;
            if (ni < 0 || ni >= N) break;
            if (abs(pos[ni] - last) > t) break;
            i = ni;
            farthest = pos[i];
            exploded++;
        }
        if (farthest == last) break;
        last = farthest;
        t++;
    }

    return exploded;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> pos(N);
    for (int i = 0; i < N; i++) {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    int maxExploded = 0;

    for (int i = 0; i < N; i++) {
        // Expand left and right from hay bale i
        int leftExploded = explodeOneDirection(pos, i, -1);
        int rightExploded = explodeOneDirection(pos, i, 1);

        // Subtract 1 to avoid double-counting starting bale
        int total = leftExploded + rightExploded - 1;
        maxExploded = max(maxExploded, total);
    }

    cout << maxExploded << endl;
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
