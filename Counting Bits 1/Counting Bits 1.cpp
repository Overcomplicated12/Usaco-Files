// Counting Bits 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    const long long MOD = 1e9 + 7;
    long long pow2 = 1;  // half of the cycle length
    long long cnt = 0;

    while (pow2 <= n) {
        // in a full cycle of length 2*pow2, there are pow2 copies of 1
        cnt += ((n + 1) / (2 * pow2)) * pow2;

        // contribution from the partial cycle
        cnt += max(0LL, (n + 1) % (2 * pow2) - pow2);

        cnt %= MOD;

        pow2 *= 2;  // move to the next bit position
    }

    cout << cnt << endl;
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
