// Diamond COllector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N, K;
    cin >> N >> K;
    vector<int> Dia;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        Dia.push_back(a);
    }

    int count = 0;
    for (int i = 0; i < N-1; i++)
    {
        if (abs(Dia[i] - Dia[i + 1]) <= K)
        {
            count++;
        }
        else
        {
            continue;
        }
    }
    cout << count + 1 << endl;

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
