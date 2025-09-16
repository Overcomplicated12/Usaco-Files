// HaybaleFlavorThing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> flavors(N);
    for (int i = 0; i < N; i++)
    {
        cin >> flavors[i];
    }

    int min_dist = INT_MAX;

    for (int flavor = 0; flavor <= 1000; flavor++)
    {
        vector<int> positions;

        for (int j = 0; j < N; j++)
        {
            if (flavors[j] == flavor)
            {
                positions.push_back(j);
            }
        }

        if (positions.size() < 2) continue;

        int l = 0;
        int r = positions.size() - 1;

        int dist = 0;
        int curr_pos = positions[l];  // Bessie starts at the leftmost

        // Alternate: right, left, right, left...
        bool turn_right = true;
        l++;  // we already used the leftmost

        while (l <= r)
        {
            if (turn_right)
            {
                dist += abs(positions[r] - curr_pos);
                curr_pos = positions[r];
                r--;
            }
            else
            {
                dist += abs(positions[l] - curr_pos);
                curr_pos = positions[l];
                l++;
            }
            turn_right = !turn_right;
        }

        min_dist = min(min_dist, dist);
    }

    cout << min_dist << endl;

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
