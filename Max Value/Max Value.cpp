// Max Value.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

const int MOD = 1e9 + 7;
int main()
{
    string n; int x;
    cin >> n >> x;
    char xc = x + '0';
    if (n[0] == '-') {
        // Negative: insert x such that the number is as big as possible (less negative)
        bool inserted = false;
        for (int i = 1; i < n.length(); i++) {
            if (xc < n[i]) { // smaller digit means less negative
                n.insert(i, 1, xc);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            n += xc;
        }
    }
    else
    {
        bool inserted = false;
        for (int i = 0; i < n.length(); i++) {
            if (xc > n[i]) { 
                n.insert(i, 1, xc);
                inserted = true;
                break;
            }
        }
        if (!inserted) {
            n += xc;
        }
    }

    long long result = 0;
    int start = (n[0] == '-') ? 1 : 0;
    for (int i = start; i < n.length(); i++) {
        result = (result * 10 + (n[i] - '0')) % MOD;
    }

    if (n[0] == '-') {
        result = -result;
    }
    
    cout << result << endl;
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
