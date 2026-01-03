// CountingSequences.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool solve1(const vector<int>& l) {
    if (l.empty()) return true;
    int mn = *min_element(l.begin(), l.end());
    int mx = *max_element(l.begin(), l.end());
    return mn == mx;
}

bool solve2(const vector<int>& l) {
    if (solve1(l)) return true;

    vector<pair<int, int>> blocks; // (len, value)
    int r = 0, n = (int)l.size();
    while (r < n) {
        int i = r;
        while (r < n && l[r] == l[i]) r++;
        blocks.push_back({ r - i, l[i] });
    }

    if ((int)blocks.size() % 2 != 0) return false;

    // blocks[2:] == blocks[:-2]
    // i.e. blocks[j] == blocks[j-2] for all j >= 2
    for (int j = 2; j < (int)blocks.size(); j++) {
        if (blocks[j] != blocks[j - 2]) return false;
    }
    return true;
}

bool solve3(const vector<int>& l) {
    int n = (int)l.size();

    for (int i = 1; i <= n; i++) {
        if (n % i != 0) continue;
        int m = n / i; // candidate period length

        // check periodic: l[0..n-m-1] == l[m..n-1]
        bool ok = true;
        for (int j = 0; j < n - m; j++) {
            if (l[j] != l[j + m]) { ok = false; break; }
        }
        if (!ok) continue;

        vector<int> sub(l.begin(), l.begin() + m);

        for (int cut = 0; cut <= m; cut++) {
            vector<int> left(sub.begin(), sub.begin() + cut);
            vector<int> right(sub.begin() + cut, sub.end());

            if (solve2(left) && solve1(right)) return true;
            if (solve1(left) && solve2(right)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<int> seq(N);
        for (int i = 0; i < N; i++) cin >> seq[i];

        bool ans = false;
        if (K == 1) ans = solve1(seq);
        else if (K == 2) ans = solve2(seq);
        else ans = solve3(seq); // K==3

        cout << (ans ? "YES\n" : "NO\n");
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
