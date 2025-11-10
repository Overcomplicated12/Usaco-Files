// GuessTheAnimal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // For USACO local file I/O. Remove/comment these lines if submitting to an online judge
    // that reads from stdin/stdout directly.
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int N;
    cin >> N;

    // characteristics[i] = list of traits for animal i
    vector<vector<string>> characteristics(N);
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;     // animal name (not used in logic)
        int K;
        cin >> K;
        characteristics[i].reserve(K);
        for (int j = 0; j < K; j++) {
            string trait;
            cin >> trait;
            characteristics[i].push_back(trait);
        }
    }

    int bestCommon = 0;

    // Check all pairs and count intersection size
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int common = 0;

            // Naive O(K_i * K_j) intersection count
            for (const string& a : characteristics[i]) {
                for (const string& b : characteristics[j]) {
                    if (a == b) common++;
                }
            }

            bestCommon = max(bestCommon, common);
        }
    }

    // Strategy needs at most (max overlap + 1) yes-answers
    cout << bestCommon + 1 << '\n';
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
