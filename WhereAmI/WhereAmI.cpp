// WhereAmI.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

// Function to check if all substrings of length k are unique
bool isUnique(string s, int k)
{
    vector<string> seen; // store all substrings we've encountered
    // iterate over all substrings of length k
    for (int i = 0; i <= s.length() - k; i++)  // <= ensures last substring is included
    {
        string sub = s.substr(i, k); // take substring of length k starting at i

        // check if this substring was already seen before
        for (string prev : seen) {
            if (prev == sub) return false; // found duplicate
        }

        // if not duplicate, store it
        seen.push_back(sub);
    }
    return true; // all substrings were unique
}

int main()
{
    // USACO input/output redirection
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N;
    cin >> N;  // length of the string

    string s;
    cin >> s;  // the mailbox colors string

    // Try each possible substring length K from 1 to N
    for (int i = 1; i <= N; i++)
    {
        // check if substrings of length i are unique
        if (isUnique(s, i)) {
            cout << i << endl;    // first valid K is the answer
            break;                // stop searching (smallest K guaranteed)
        }
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
