// RoundaboutRounding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int get_digit_by_index(int num, int index) {
    // Handle negative index case
    if (index < 0) return -1;

    // Take the absolute value of the number to work with positive numbers
    num = std::abs(num);

    // Extract the digit by dividing the number by 10^index
    for (int i = 0; i < index; ++i) {
        num /= 10;  // Shift the number right by 1 digit
    }

    return num % 10;  // Return the rightmost digit
}
int countDigit(int n) {
    return (n == 0) ? 1 : log10(n) + 1;
}
int bessierounding(int n)
{
    int a = n;
    int b = countDigit(n) - 2;
    int c = b + 1;

    int roundto = pow(10, c);
    int x = get_digit_by_index(a, c);

    if (x >= 5)
    {
        a += roundto;

    }
    a = (a / roundto) * roundto;


    return a;
}
int chainRounding(int num) {
    int b = countDigit(num);  // Total number of digits

    for (int i = 1; i < b; i++)
    {
        int x = (num / static_cast<int>(pow(10, i - 1))) % 10;
        int toround = pow(10, i);
        if (x >= 5)
        {
            num += toround;

        }
        num = (num / toround) * toround;
    }
    return num;
}

int main() {
    int T;
    cin >> T;

    vector<int> n(T);
    for (int i = 0; i < T; i++) {
        cin >> n[i];
    }

    vector<int> counts;
    for (int z : n) {
        int count = 0;
        for (int i = 2; i <= z; i++) {
            int br = bessierounding(i);
            int cr = chainRounding(i);

            if (br != cr) {
                count++;
            }
        }
        counts.push_back(count);
    }

    for (int nums : counts) {
        cout << nums << endl;
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
