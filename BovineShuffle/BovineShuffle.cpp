// BovineShuffle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> cows(n);
    vector<int> pos(n);
    vector<int> new_cows(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i];
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
        {
            new_cows[j] = cows[pos[j]-1];
           
        }
        cows = new_cows;
    }
    for (int c:new_cows)
    {
        cout << c << endl;
    }

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
