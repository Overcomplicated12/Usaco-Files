// Measuring Traffic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
const int large = 1e9; // Represents an arbitrarily large number for "infinite" upper bound
using namespace std;

int main()
{
    // Redirect input and output to files (USACO format)
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n;
    cin >> n; // Number of road segments

    vector<string> seg(n); // Type of each segment: "on", "off", or "none"
    vector<int> start(n);  // Lower bound for traffic change/restriction
    vector<int> end(n);    // Upper bound for traffic change/restriction

    // Read each segment's type and values
    for (int i = 0; i < n; i++)
    {
        cin >> seg[i] >> start[i] >> end[i];
    }

    // ------------------------------------------------
    // FIRST PASS: Work backwards to find possible range
    // before entering the first segment.
    // ------------------------------------------------
    int low = 0;        // Minimum possible number of cars
    int high = large;   // Maximum possible number of cars

    for (int i = n - 1; i >= 0; i--) // Go from last segment to first
    {
        if (seg[i] == "none")
        {
            // "none" means a restriction: actual count must be between start[i] and end[i]
            low = max(low, start[i]);
            high = min(high, end[i]);
        }
        else if (seg[i] == "off")
        {
            // "off" forward means cars leave, so going backwards means cars joined earlier
            low += start[i];
            high += end[i];
        }
        else if (seg[i] == "on")
        {
            // "on" forward means cars join, so going backwards means cars left earlier
            low -= end[i];
            high -= start[i];

            // Prevent negative car counts
            high = max(0, high);
            low = max(0, low);
        }
    }

    // Output the possible range before the first segment
    cout << low << ' ' << high << endl;

    // ------------------------------------------------
    // SECOND PASS: Work forwards to find possible range
    // after passing the last segment.
    // ------------------------------------------------
    low = 0;
    high = large;

    for (int i = 0; i < n; i++) // Go from first segment to last
    {
        if (seg[i] == "none")
        {
            // Restriction on car count within this segment
            low = max(low, start[i]);
            high = min(high, end[i]);
        }
        else if (seg[i] == "on")
        {
            // Cars join the road
            low += start[i];
            high += end[i];
        }
        else if (seg[i] == "off")
        {
            // Cars leave the road
            low -= end[i];
            high -= start[i];

            // Prevent negative counts
            high = max(0, high);
            low = max(0, low);
        }
    }

    // Output the possible range after the last segment
    cout << low << ' ' << high << endl;
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
