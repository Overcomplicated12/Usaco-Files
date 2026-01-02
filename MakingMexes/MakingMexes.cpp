// MakingMexes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> cnt(N + 1, 0);
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (0 <= x && x <= N) cnt[x]++;
    }

    int missing = 0; // missing numbers in [0, m-1]
    for (int m = 0; m <= N; m++) {
        if (m > 0 && cnt[m - 1] == 0) missing++; // now we require (m-1)
        int ans = max(missing, cnt[m]);          // remove all m's and fill missing
        cout << ans << "\n";
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
