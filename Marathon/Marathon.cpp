// Marathon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int x[100000], y[100000];
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    int totalDistance = 0;
    for (int i = 1; i < n; i++) {
        totalDistance += abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    }
    int largestSkip = 0;
    for (int i = 1; i < n - 1; i++) {
        int noSkip = abs(x[i] - x[i - 1]) + abs(x[i + 1] - x[i]) +
            abs(y[i] - y[i - 1]) + abs(y[i + 1] - y[i]);
        int skip = abs(x[i + 1] - x[i - 1]) + abs(y[i + 1] - y[i - 1]);
        largestSkip = max(largestSkip, noSkip - skip);
    }

    cout << totalDistance - largestSkip << endl;

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
