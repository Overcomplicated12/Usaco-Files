// BreedFlip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;

    vector <bool> diff(N + 1);

    for (int i = 0; i < N; i++)
    {
        diff[i + 1] = a[i] != b[i];
    }

    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        if (!diff[i] && diff[i + 1]) { counter++; }
    }

    cout << counter << endl;

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
