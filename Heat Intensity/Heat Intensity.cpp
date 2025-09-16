// Heat Intensity.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    double best = 0.0;

    // Try every starting point
    for (int i = 0; i < N; i++) {
        long long sum = 0;
        // Grow the subarray step by step
        for (int j = i; j < N; j++) {
            sum += a[j]; // extend window to include a[j]
            int length = j - i + 1;
            if (length >= K) {
                double avg = (double)sum / length;
                best = max(best, avg);
            }
        }
    }
    long long scaled = (long long)(floor(best * 1000000));
    long long integer_part = scaled / 1000000;
    long long fractional_part = scaled % 1000000;

    cout << integer_part << ".";

    // pad fractional part with leading zeros
    string frac = to_string(fractional_part);
    while ((int)frac.size() < 6) frac = "0" + frac;

    cout << frac << "\n";

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
