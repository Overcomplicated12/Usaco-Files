// AstralSuperposition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<string> rows(N);
    for (auto& row : rows) cin >> row;

    vector<vector<bool>> star(N, vector<bool>(N, false));

    // Handle 'B'
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (rows[i][j] == 'B') {
                if (i - B < 0 || j - A < 0) return -1;
                star[i][j] = true;
                star[i - B][j - A] = true;
            }
        }
    }

    // Handle 'W' and 'G'
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

            if (rows[i][j] == 'W') {
                if (star[i][j]) return -1;
            }
            else if (rows[i][j] == 'G') {
                if (star[i][j]) continue; // already satisfied here
                if (i >= B && j >= A && star[i - B][j - A]) continue; // satisfied by partner
                star[i][j] = true;
            }

        }
    }

    int ans = 0;
    for (auto& r : star) {
        for (bool v : r) ans += v;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) cout << solve() << "\n";
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
