// Counting Liars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, char>> cows(n);

    for (int i = 0; i < n; i++) {
        cin >> cows[i].second >> cows[i].first;
    }

    vector<int> G, L;

    // Separate cows into G and L
    for (int i = 0; i < n; i++) {
        if (cows[i].second == 'G') {
            G.push_back(cows[i].first);
        }
        else if (cows[i].second == 'L') {
            L.push_back(cows[i].first);
        }
    }

    sort(G.begin(), G.end());
    sort(L.begin(), L.end());

    // If the tallest good cow is smaller than or equal to the shortest liar cow
    if (G.back() <= L.front()) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> liars;

    // Corrected logic for calculating liars to remove
    for (int i = G.size() - 1; i >= 0; i--) { // Start from G.size() - 1
        int temp = G.size() - (i + 1);
        for (int t : L) {
            if (t < G[i]) {
                temp++;
            }
        }
        liars.push_back(temp);
    }

    // Second loop to check liars removal for L cows
    for (int i = 0; i < L.size(); i++) {
        int temp = i;
        for (int t : G) {
            if (t > L[i]) {
                temp++;
            }
        }
        liars.push_back(temp);
    }

    int ans = *min_element(liars.begin(), liars.end());
    cout << ans << endl;

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
