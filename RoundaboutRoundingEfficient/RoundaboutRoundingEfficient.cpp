// RoundaboutRoundingEfficient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
long long maxnum[8] = { 49,499,4999,49999,499999,4999999,49999999,499999999 };
long long minnum[8] = { 45,445,4445,44445,444445,4444445,44444445,444444445 };
long long totals[8] = { 5,55,555,5555,55555,555555,5555555,55555555 };
long long rangesmin[8] = { 10,100,1000,10000,100000,1000000,10000000,100000000 };
long long rangesmax[8] = { 100,1000,10000,100000,1000000,10000000,100000000, 1000000000 };

long long solve(long long n)
{
    long long count = 0;
    if (n <= 10)
    {
        return 0;
    }
    for (int i = 0; i < 8; i++)
    {
        if (n > rangesmin[i] && n > rangesmax[i])
        {
            count += totals[i];
        }
        else if (n > rangesmin[i] && n <= rangesmax[i])
        {
            count += totals[i];
            if (n >= maxnum[i])
            {
                break;
            }
            else if (n <= maxnum[i] && n >= minnum[i])
            {
                long long subby = abs(maxnum[i] - n);
                count -= subby;
            }
            else
            {
                count -= totals[i];
            }
        }

    }
    return count;
}
int main()
{
    long long t;
    cin >> t;
    vector <long long> N;
    for (int i = 0; i < t; i++)
    {
        long long temp;
        cin >> temp;
        N.push_back(temp);
    }

    for (int i = 0; i < t; i++)
    {
        cout << solve(N[i]) << endl;
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
