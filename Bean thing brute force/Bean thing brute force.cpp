// Bean thing brute force.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int ans = INT_MAX; // Initialize to large number

    // Try using A[i] as the target value
    for (int i = 0; i < n; ++i) {
        int target = A[i];
        int removed = 0;

        for (int j = 0; j < n; ++j) {
            if (A[j] >= target) {
                removed += A[j] - target; // trim down to target
            }
            else {
                removed += A[j]; // remove the whole bag
            }
        }

        ans = min(ans, removed);
    }

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
