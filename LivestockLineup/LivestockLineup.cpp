// LivestockLineup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

const vector<string> COWS = {
    "Beatrice",
    "Belinda",
    "Bella",
    "Bessie",
    "Betsy",
    "Blue",
    "Buttercup",
    "Sue"
};

int main()
{

    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
  
    map<string, int> cow_inds;
    for (int i = 0; i < COWS.size(); i++) {
        cow_inds[COWS[i]] = i;
    }

    int n;
    cin >> n;

    vector<vector<int>> neighbors(8);
    for (int i = 0; i < n; i++) {
        string cow1, cow2, trash;
        cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;

        int c1 = cow_inds[cow1];
        int c2 = cow_inds[cow2];
        neighbors[c1].push_back(c2);
        neighbors[c2].push_back(c1);
    }

    vector<bool> added(8, false);
    vector<int> order;

    // First process all chain endpoints (degree <= 1)
    for (int c = 0; c < 8; c++) {
        if (!added[c] && neighbors[c].size() <= 1) {

            // Start the chain
            added[c] = true;
            order.push_back(c);

            if (neighbors[c].size() == 1) {
                int prev = c;
                int at = neighbors[c][0];

                while (neighbors[at].size() == 2) {
                    added[at] = true;
                    order.push_back(at);

                    int next = (neighbors[at][0] == prev
                        ? neighbors[at][1]
                        : neighbors[at][0]);

                    prev = at;
                    at = next;
                }

                added[at] = true;
                order.push_back(at);
            }
        }
    }

    // Print result
    for (int c : order) {
        cout << COWS[c] << "\n";
    }
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
