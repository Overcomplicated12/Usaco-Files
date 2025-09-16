// LoadBalancing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    // USACO input/output redirection
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int N, B;
    cin >> N >> B;   // N = number of cows, B = coordinate bound (not directly used here)

    // Store cow coordinates
    vector<int> x_vals(N);
    vector<int> y_vals(N);

    // Candidate fence positions (vertical and horizontal)
    set<int> vfence;
    set<int> hfence;

    // Read cow positions
    for (int i = 0; i < N; i++)
    {
        cin >> x_vals[i] >> y_vals[i];

        // Add candidate fence lines *just after* each cow’s x and y
        // (fences must lie between cows, not through them)
        vfence.insert(x_vals[i] + 1);
        hfence.insert(y_vals[i] + 1);
    }

    int ans = N;  // start with the worst-case (all cows in one quadrant)

    // Try every possible fence combination
    for (int v : vfence) {       // vertical fence candidate
        for (int h : hfence) {   // horizontal fence candidate

            // Counts for cows in each quadrant
            int top_left = 0;
            int top_right = 0;
            int bottom_left = 0;
            int bottom_right = 0;

            // Place all cows into the correct quadrant
            for (int c = 0; c < N; c++) {
                if (x_vals[c] < v && y_vals[c] > h) {
                    top_left++;
                }
                else if (x_vals[c] > v && y_vals[c] > h) {
                    top_right++;
                }
                else if (x_vals[c] < v && y_vals[c] < h) {
                    bottom_left++;
                }
                else if (x_vals[c] > v && y_vals[c] < h) {
                    bottom_right++;
                }
            }

            // The "balance" is determined by the maximum cows in any quadrant
            // We want to minimize that maximum
            ans = min(ans,
                max({ top_left, top_right, bottom_left, bottom_right }));
        }
    }

    cout << ans << endl;
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
