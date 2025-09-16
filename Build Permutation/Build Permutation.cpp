// Build Permutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {

    int n, a, b;
    cin >> n >> a >> b;

    if (a + b > n - 2 || abs(a - b) > 1) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> ans;
    int low = 1, high = n;

    bool takeLow = (a >= b); // start with low if peaks >= valleys
    for (int i = 0; i < a + b + 1; i++) {
        if (takeLow) ans.push_back(low++);
        else ans.push_back(high--);
        takeLow = !takeLow;
    }

    if (ans.back() < ans[ans.size() - 2]) {
        for (int x = low; x <= high; x++) ans.push_back(x);
    }
    else {
        for (int x = high; x >= low; x--) ans.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << (i + 1 == n ? '\n' : ' ');
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
