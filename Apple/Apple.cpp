// Apple.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> apples(n);
    long long total_weight = 0;

    // Input weights of apples and calculate total weight
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        total_weight += apples[i];
    }

    long long min_difference = total_weight;

    // Iterate over all possible subsets using bitmasking
    for (int mask = 0; mask < (1 << n); mask++) {
        long long group1_weight = 0;

        // Calculate the weight of the first group
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                group1_weight += apples[i];
            }
        }

        // Calculate the weight of the second group
        long long group2_weight = total_weight - group1_weight;

        // Calculate the absolute difference and update the minimum difference
        long long difference = abs(group1_weight - group2_weight);
        min_difference = min(min_difference, difference);
    }

    // Output the minimum difference
    cout << min_difference << endl;

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
