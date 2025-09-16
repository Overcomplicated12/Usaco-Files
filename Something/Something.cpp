// Something.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

int c[3], m[3];

int pour(int a,int b) 
{
    int d = min(m[a], c[b] - m[b]);
    m[a] -= d;
    m[b] += d;
}
int main()
{
    
    for (int i = 0; i < 3; i++)
    {
        cin >> c[i] >> m[i];
    }

    for (int i = 0; i < 100; i++)
    {
        pour(i % 3, (i + 1) % 3);
    }

    for (int i = 0; i < 3; i++)
    {
        cout << m[i] << endl;
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
