// AcowdemiaII example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    unordered_map<string, int> members;
    vector<string> names(n);

    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        members[names[i]] = i;
    }

    vector<vector<char>> answer(n, vector<char>(n, '?'));
    for (int i = 0; i < n; ++i) {
        answer[i][i] = 'B';
    }

    for (int j = 0; j < k; ++j) {
        vector<string> publication(n);
        for (int i = 0; i < n; ++i) {
            cin >> publication[i];
        }

        for (int x = 0; x < n; ++x) {
            bool alphabetical = true;
            for (int y = x + 1; y < n; ++y) {
                if (publication[y - 1] > publication[y]) {
                    alphabetical = false;
                }
                if (!alphabetical) {
                    int a = members[publication[x]];
                    int b = members[publication[y]];
                    answer[a][b] = '0';
                    answer[b][a] = '1';
                    
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (char c : answer[i]) {
            cout << c;
        }
        cout << '\n';
    }

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
