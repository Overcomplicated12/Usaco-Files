// Stuck in a rut.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// Stores north-facing cows as {x, y, index}
vector<array<int, 3>> north;
// Stores east-facing cows as {x, y, index}
vector<array<int, 3>> east;

int INF = 1e9;

int main()
{
    int n;
    cin >> n;
    // pos[i] = original starting position of the i-th cow
    vector<pair<int, int>> pos(n);

    // ==============================
    // Step 1: Read and classify input
    // ==============================
    for (int i = 0; i < n; i++)
    {
        char dir; // 'N' or 'E'
        cin >> dir;

        pair<int, int> p;
        cin >> p.first >> p.second; // starting coordinates

        // Store {x, y, index} for each cow
        array<int, 3> varr = { p.first, p.second, i };
        if (dir == 'E')
        {
            east.push_back(varr); // East-facing cows
        }
        else
        {
            north.push_back(varr); // North-facing cows
        }
        pos[i] = p; // Keep the original position for later lookups
    }

    // ==============================================
    // Step 2: Find potential blocking events (meetTime)
    // ==============================================
    // meetTime entries: {time, blockedCowID, blockerCowID, flag}
    // flag = 0 → blocker is north cow stopping east cow
    // flag = 1 → blocker is east cow stopping north cow
    vector<vector<int>> meetTime;

    // Compare every north cow with every east cow
    for (auto nC : north)
    {
        for (auto eC : east)
        {
            // Vertical distance (y) the north cow needs to travel
            int yT = eC[1] - nC[1];
            // Horizontal distance (x) the east cow needs to travel
            int xT = nC[0] - eC[0];

            // If they would meet at the same time, neither blocks the other
            if (xT == yT) continue;

            // Case 1: East cow reaches intersection first → stops north cow
            if (yT > xT && xT > 0)
            {
                // yT = time north cow would take before being blocked
                meetTime.push_back({ yT, nC[2], eC[2], 0 });
            }
            // Case 2: North cow reaches intersection first → stops east cow
            else if (yT < xT && yT > 0)
            {
                // xT = time east cow would take before being blocked
                meetTime.push_back({ xT, eC[2], nC[2], 1 });
            }
        }
    }

    // ===========================================================
    // Step 3: Sort blocking events by earliest "blocked cow time"
    // ===========================================================
    // This ensures earlier stops are processed before later ones
    sort(meetTime.begin(), meetTime.end());

    // =======================================
    // Step 4: Process events and record stops
    // =======================================
    vector<int> ans(n, INF); // INF means "never stopped"

    for (auto mt : meetTime)
    {
        // mt[0] = time to stop blocked cow
        // mt[1] = blocked cow ID
        // mt[2] = blocker cow ID
        // mt[3] = 0 if north stops east, 1 if east stops north

        // If both cows are still moving, block the blocked cow now
        if (ans[mt[2]] == INF && ans[mt[1]] == INF)
        {
            ans[mt[1]] = mt[0];
            continue;
        }

        // If blocked cow is still moving, check if blocker actually gets there
        if (ans[mt[1]] == INF)
        {
            if (mt[3]) // blocker is east cow → compare Y positions
            {
                int start = pos[mt[2]].second;      // starting Y of east cow
                int end = start + ans[mt[2]];       // last Y east cow reaches before stopping
                if (pos[mt[1]].second >= start && pos[mt[1]].second <= end)
                {
                    ans[mt[1]] = mt[0];
                }
            }
            else // blocker is north cow → compare X positions
            {
                int start = pos[mt[2]].first;       // starting X of north cow
                int end = start + ans[mt[2]];       // last X north cow reaches before stopping
                if (pos[mt[1]].first >= start && pos[mt[1]].first <= end)
                {
                    ans[mt[1]] = mt[0];
                }
            }
        }
    }

    // =====================
    // Step 5: Output results
    // =====================
    for (auto v : ans)
    {
        if (v == INF)
        {
            cout << "Infinity" << endl;
        }
        else
        {
            cout << v << endl;
        }
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
