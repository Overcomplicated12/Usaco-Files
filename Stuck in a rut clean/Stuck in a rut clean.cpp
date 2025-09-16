// Stuck in a rut clean.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

vector<array<int, 3>> north;
vector<array<int, 3>> east;
int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> pos(n);

    for (int i = 0; i < n; i++) {
        char dir;
        cin >> dir;
        pair<int, int> p;
        cin >> p.first >> p.second;
        array<int, 3> varr = { p.first, p.second, i };
        if (dir == 'E') east.push_back(varr);
        else north.push_back(varr);
        pos[i] = p;
    }

    vector<vector<int>> meetTime;
    for (auto nC : north) {
        for (auto eC : east) {
            int yT = eC[1] - nC[1];
            int xT = nC[0] - eC[0];
            if (xT == yT) continue;
            if (yT > xT && xT > 0) {
                meetTime.push_back({ yT, nC[2], eC[2], 0 });
            }
            else if (yT < xT && yT > 0) {
                meetTime.push_back({ xT, eC[2], nC[2], 1 });
            }
        }
    }

    sort(meetTime.begin(), meetTime.end());
    vector<int> ans(n, INF);

    for (auto mt : meetTime) {
        if (ans[mt[2]] == INF && ans[mt[1]] == INF) {
            ans[mt[1]] = mt[0];
            continue;
        }
        if (ans[mt[1]] == INF) {
            if (mt[3]) {
                int start = pos[mt[2]].second;
                int end = start + ans[mt[2]];
                if (pos[mt[1]].second >= start && pos[mt[1]].second <= end) {
                    ans[mt[1]] = mt[0];
                }
            }
            else {
                int start = pos[mt[2]].first;
                int end = start + ans[mt[2]];
                if (pos[mt[1]].first >= start && pos[mt[1]].first <= end) {
                    ans[mt[1]] = mt[0];
                }
            }
        }
    }

    for (auto v : ans) {
        if (v == INF) cout << "Infinity" << endl;
        else cout << v << endl;
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
