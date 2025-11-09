// ZigZagConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Problem statement:
//Zig zag conversion(b05)
//The string "BRONZEISHARD" is written in a zigzag pattern on a given number of rows like this:
//B Z H
//R N E S A D
//O I R
//And then read line by line : "BZHRNESADOIR"
//Input(from terminal / stdin)
// The first line contains the string s, with all upper case letters A~Z and length ≤ 1000.
// The second line contains the number of rows 𝑛, 1 ≤ 𝑛 ≤ 10.
//Output(to terminal / stdout)
// Treat the result string as a base - 26 integer, where A = 0, B = 1, ..., Z = 25. Report its value in base -
//10, modulo 1e9 + 7.
//Sample input
//ABCD
//2
//Sample output
//1381
//Explanation: The final string is ACBD, or 0213 in base 26. Its value in base - 10 is 1381.
//A C
//B D
//Sample input 2
//BRONZEISHARD
//4
//Sample output
//765993961
//Explanation: The final string is BIRESDOZHRNA :
//B I
//R E S D
//O Z H R
//N A

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
const long long MOD = 1'000'000'007LL;

int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;

    if (n == 1 || n >= (int)s.size())
    {
        long long val = 0;
        for (char c : s)
        {
            int d = c - 'A';
            val = (val * 26 + d) % MOD;
        }

        cout << val << endl;
        return 0;
    }

    vector<string> rows(n);
    int r = 0, dir = 1;
    for (char c : s)
    {
        rows[r].push_back(c);
        r += dir;
        if (r == 0 || r == n - 1) dir *= -1;
    }

    string t;
    t.reserve(s.size());
    for (auto row : rows) t += row;

    long long ans = 0;
    for (char c : t)
    {
        int d = c - 'A';
        ans = (ans * 26 + d) % MOD;
    }

    cout << ans << endl;
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
