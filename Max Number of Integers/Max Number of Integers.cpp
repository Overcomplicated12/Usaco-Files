// Max Number of Integers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n, m, s;
    cin >> n >> m >> s;  // Read the number of forbidden numbers, max number, and max allowed sum

    // Create a boolean vector to mark forbidden numbers
    // forbidden[i] will be true if number i is forbidden
    vector<bool> forbidden(m + 1, false);

    // Mark the forbidden numbers
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;           // Read a forbidden number
        if (x <= m)          // Only mark if within the allowed range
            forbidden[x] = true;
    }

    int sum = 0;   // To keep track of the sum of chosen numbers
    int count = 0; // To count how many numbers we can choose

    // Try to choose numbers from 1 to m
    for (int i = 1; i <= m; i++)
    {
        if (forbidden[i]) continue;   // Skip forbidden numbers
        if (sum + i > s) break;       // Stop if adding this number exceeds the allowed sum
        sum += i;                      // Add the number to the sum
        count++;                        // Increase the count of chosen numbers
    }

    cout << count << endl;  // Output the total count of chosen numbers
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
