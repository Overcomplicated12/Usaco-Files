// COWROAD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("crossroad.in", "r", stdin);
    freopen("crossroad.out", "w", stdout);
    int arr[100][2];
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
    }
    int count = 0;

    for (int i = 1; i <= 10; i++) // for each cow ID
    {
        int prev = -1; // only reset once per cow
        for (int j = 0; j < N; j++) // loop through all observations
        {
            if (arr[j][0] == i) // if the current observation is about cow i
            {
                if (prev != -1 && prev != arr[j][1])
                {
                    count++;
                    prev = arr[j][1];
                }
                else if (prev == -1)
                {
                    prev = arr[j][1]; // first time seeing this cow
                }
            }
        }
    }

    cout << count << endl;
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
