// Cow Gymnastics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int mp[20][20], rankings[10][20];

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N;
    cin >> K >> N;

    // Read rankings
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            cin >> rankings[i][j];
            rankings[i][j]--; // convert to 0-based
        }
    }

    // Count pairwise dominance
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                mp[rankings[i][j]][rankings[i][k]]++;
            }
        }
    }

    int ans = 0;
    // Check consistency
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mp[i][j] == K) ans++;
        }
    }

    cout << ans << "\n";
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
