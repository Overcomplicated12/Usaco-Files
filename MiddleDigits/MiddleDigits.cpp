// MiddleDigits.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//Problem statment:
//Middle digit(b04)
//Given integer 𝑛, find the middle digit of 7௡ if it has an odd number of digits, the middle two digits if it has
//an even number of digits.
//Input(from terminal / stdin)
// The only line contains integer 𝑛, 1 ≤ 𝑛 ≤ 1000.
//Output(to terminal / stdout)
// Report the middle digit or the middle two digits.
//Sample input 1
//3
//Sample output 1
//4
//Sample input 2
//6
//Sample output 2
//76


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long sixsept = 7;
int main()
{
    int n;
    cin >> n;

    vector<int>digits;
    digits.push_back(1);

    for (int i = 0; i < n; i++)
    {
        int carry = 0;
        for (int j = 0; j < digits.size(); j++)
        {
            long long val = digits[j] * sixsept + carry;
            digits[j] = val % 10;
            carry = val / 10;
        }
        while (carry) {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    reverse(digits.begin(), digits.end());

    int len = digits.size();

    if (len % 2 == 1)
    {
        cout << digits[len / 2] << endl;
    }
    else
    {
        cout << digits[len / 2 - 1] << digits[len / 2] << endl;
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
