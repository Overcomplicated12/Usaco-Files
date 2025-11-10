// Hoofball.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // USACO file I/O
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    int N;
    cin >> N;
    vector<int> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];

    // 1) Sort positions so we can decide nearest neighbors by index.
    sort(x.begin(), x.end());

    // to[i] = index that cow i passes to; indeg[j] = how many pass to j
    vector<int> to(N, -1), indeg(N, 0);

    // 2) Build the directed graph: each cow passes to the nearest neighbor.
    for (int i = 0; i < N; i++) {
        if (i == 0) to[i] = 1;                // left end: must pass right
        else if (i == N - 1) to[i] = N - 2;   // right end: must pass left
        else {
            int dl = x[i] - x[i - 1];
            int dr = x[i + 1] - x[i];
            // Tie goes to the left neighbor per problem statement
            to[i] = (dl <= dr) ? i - 1 : i + 1;
        }
        indeg[to[i]]++;
    }

    int ans = 0;

    // 3) Each zero-indegree node needs a new ball (a new starting throw).
    for (int i = 0; i < N; i++) {
        if (indeg[i] == 0) ans++;
    }

    // 4) Handle isolated mutual pairs (2-cycles) where both nodes have indegree 1.
    // These components are not reached by anyone else, but a single extra ball
    // suffices to cover each such pair.
    for (int i = 0; i + 1 < N; i++) {
        if (to[i] == i + 1 && to[i + 1] == i) {        // mutual pair
            if (indeg[i] == 1 && indeg[i + 1] == 1)    // isolated (no extra in-edges)
                ans++;
        }
    }

    cout << ans << '\n';
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
