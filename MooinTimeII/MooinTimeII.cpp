// MooinTimeII.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) cin >> a[i];

    vector<int> first(N + 1, 0), last(N + 1, 0), secondLast(N + 1, 0);

    // Pass 1: first/last/secondLast
    for (int i = 1; i <= N; i++) {
        int v = a[i];
        if (first[v] == 0) first[v] = i;
        secondLast[v] = last[v]; // previous last becomes second-to-last
        last[v] = i;
    }

    // Pass 2: prefix distinct counts
    vector<int> prefDistinct(N + 1, 0);
    vector<char> seen(N + 1, 0);
    int distinct = 0;
    for (int i = 1; i <= N; i++) {
        int v = a[i];
        if (!seen[v]) {
            seen[v] = 1;
            distinct++;
        }
        prefDistinct[i] = distinct;
    }

    // Pass 3: compute answer
    long long ans = 0;
    for (int y = 1; y <= N; y++) {
        if (secondLast[y] == 0) continue;          // need at least 2 occurrences
        int t = secondLast[y] - 1;                 // prefix ends before second-to-last y
        if (t <= 0) continue;                      // empty prefix -> adds 0
        long long cnt = prefDistinct[t];           // distinct x in prefix
        if (first[y] != 0 && first[y] <= t) cnt--; // exclude x == y if present
        ans += cnt;
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
