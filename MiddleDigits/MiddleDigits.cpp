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
using namespace std;

long long sixsept = 7; // The base number (we are computing 7^n)

int main()
{
    int n;
    cin >> n;   // Read exponent

    // We store the number as a vector of digits (in reverse order).
    // Example: number 1234 is stored as {4, 3, 2, 1}.
    vector<int> digits;
    digits.push_back(1); // Start with 7^0 = 1

    // Multiply by 7 exactly n times to compute 7^n manually (big integer multiplication)
    for (int i = 0; i < n; i++)
    {
        int carry = 0;
        for (int j = 0; j < digits.size(); j++)
        {
            // Multiply digit by 7 + add carry
            long long val = digits[j] * sixsept + carry;

            // Store the last digit of the result
            digits[j] = val % 10;

            // Carry the remaining part
            carry = val / 10;
        }

        // If there is leftover carry, add those digits
        while (carry)
        {
            digits.push_back(carry % 10);
            carry /= 10;
        }
    }

    // The digits are currently reversed; correct the order.
    reverse(digits.begin(), digits.end());

    int len = digits.size(); // Total number of digits in 7^n

    // If the number of digits is odd → print the single middle digit
    // If even → print the middle two digits
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
