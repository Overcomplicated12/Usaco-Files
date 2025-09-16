// MeasuringTraffic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
const int large = 1e9;
using namespace std;
int main()
{
    

    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n;
    cin >> n;

    vector<string> seg(n);
    vector<int> start(n);
    vector<int> end(n);

    for (int i = 0; i < n; i++)
    {
        cin >> seg[i] >> start[i] >> end[i];
    }

    int low = 0;
    int high = large;

    for (int i = n - 1; i >= 0; i--)
    {
        if (seg[i] == "none")
        {
            low = max(low, start[i]);
            high = min(high, end[i]);
        }
        else if (seg[i] == "off")
        {
            low += start[i];
            high += end[i];
        }
        else if (seg[i] == "on")
        {
            low -= end[i];
            high -= start[i];

            high = max(0, high);
            low = max(0, low);
        }
    }
    
    cout << low << ' ' << high << endl;

    low = 0;
    high = large;

    for (int i = 0; i < n; i++)
    {
        if (seg[i] == "none")
        {
            low = max(low, start[i]);
            high = min(high, end[i]);
        }
        else if (seg[i] == "on")
        {
            low += start[i];
            high += end[i];
        }
        else if (seg[i] == "off")
        {
            low -= end[i];
            high -= start[i];
            high = max(0, high);
            low = max(0, low);
        }
    }

    cout << low <<' ' << high << endl;
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
