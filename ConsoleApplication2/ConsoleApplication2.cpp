// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int a[1001];
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int numbers = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[i] != a[j])
            {
                if (a[i] == 0)
                {
                    break;
                }
                else if (a[i] % a[j] == 0)
                {
                    count++;
                    if (count > 2)
                    {
                        break;
                    }
                }
                else
                {
                    continue;
                }
            }
            
            
        }
        if (count == 2)
        {
            numbers++;
        }
    }
    cout << numbers << endl;
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
