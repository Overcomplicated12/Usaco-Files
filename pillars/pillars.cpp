// pillars.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;
    int yesCount = 0;

    while (Q--) {
        int N;
        cin >> N;
        vector<int> R(N + 1);
        vector<int> pos(N + 1);

        for (int i = 1; i <= N; i++) {
            cin >> R[i];
            pos[R[i]] = i;  // remember where each disk is
        }

        int L = pos[N], Rpos = pos[N];
        bool possible = true;

        for (int k = N - 1; k >= 1; k--) {
            int p = pos[k];
            if (p == L - 1) {
                L = p; // extend left
            }
            else if (p == Rpos + 1) {
                Rpos = p; // extend right
            }
            else {
                possible = false;
                break;
            }
        }

        if (possible) yesCount++;
    }

    cout << yesCount << "\n";
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
