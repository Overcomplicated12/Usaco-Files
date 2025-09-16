// BlockGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    // Redirect standard input/output to USACO file format
    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;  // number of word pairs

    // ans[i] will store how many times we need the letter ('a' + i)
    vector<int> ans(26, 0);

    // Process each pair of words
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;

        // Count frequency of each letter in both words
        int ca[26] = { 0 }, cb[26] = { 0 };
        for (char ch : a) ca[ch - 'a']++;  // frequency in word a
        for (char ch : b) cb[ch - 'a']++;  // frequency in word b

        // For each letter, we need the maximum count across both words
        // (since blocks must be able to spell either word)
        for (int L = 0; L < 26; ++L) {
            ans[L] += max(ca[L], cb[L]);
        }
    }

    // Output the total counts for each letter
    for (int i = 0; i < 26; i++) {
        cout << ans[i] << endl;
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
