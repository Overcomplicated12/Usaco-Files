// SocialDistancingII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    // Redirect input/output to files for USACO-style submission
    freopen("socdist1.in", "r", stdin);
    freopen("socdist1.out", "w", stdout);

    int N;         // Number of stalls in the barn
    string s;      // Barn layout: '0' = empty stall, '1' = occupied stall
    cin >> N >> s;

    // Edge case: no cows currently in the barn
    // Place two cows at the ends to maximize distance
    if (s.find('1') == string::npos) {
        cout << N - 1 << "\n";  // Distance between two cows at the ends
        return 0;
    }

    int prev = -1;       // Index of the previous occupied stall
    int bestSameSeg = 0; // Best D if placing both cows in the same empty segment
    int best1 = 0, best2 = 0; // Two largest single-cow distances from different segments

    // Loop through all stalls to analyze empty segments
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            if (prev == -1) {
                // Leading zeros: segment before the first existing cow
                int L = i; // Length of leading empty segment
                best1 = max(best1, L);       // Best distance for placing one cow
                bestSameSeg = max(bestSameSeg, L / 2); // Two cows in same segment
            }
            else {
                // Interior zeros: segment between two existing cows
                int L = i - prev - 1; // Length of empty segment
                if (L > 0) {
                    int single = (L + 1) / 2; // Max distance if placing one cow in the middle
                    // Keep track of two largest single-cow segments
                    if (single > best1) { best2 = best1; best1 = single; }
                    else if (single > best2) best2 = single;

                    // Max distance if placing two cows in the same interior segment
                    bestSameSeg = max(bestSameSeg, (L + 1) / 3);
                }
            }
            prev = i; // Update previous occupied stall
        }
    }

    // Trailing zeros: segment after the last existing cow
    if (prev != N - 1) {
        int L = N - 1 - prev; // Length of trailing empty segment
        int single = L;       // Single-cow distance = full segment
        if (single > best1) { best2 = best1; best1 = single; }
        else if (single > best2) best2 = single;

        bestSameSeg = max(bestSameSeg, L / 2); // Two cows in same trailing segment
    }

    // Candidate max distance: either placing two cows in same segment
    // or placing them in the two largest single-cow segments
    int cand = max(bestSameSeg, min(best1, best2));

    // Minimum distance between existing cows (cannot exceed this)
    int minDist = INT_MAX;
    prev = -1;
    for (int i = 0; i < N; i++) {
        if (s[i] == '1') {
            if (prev != -1) minDist = min(minDist, i - prev);
            prev = i;
        }
    }

    // Final answer: cannot be larger than minimum existing spacing
    if (minDist != INT_MAX) cand = min(cand, minDist);

    cout << cand << endl; // Output the maximum achievable distance
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
