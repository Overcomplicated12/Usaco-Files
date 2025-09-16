// Magic Bus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
    int Q;
    cin >> Q;
    
    while (Q--)
    {
        int N, C;
        cin >> N >> C;
        
        vector<int> seats(1000001, 0);
        for (int i = 0; i < N; i++)
        {
            int p, f, t;

            cin >> p >> f >> t;
            for (int j = f; j < t; j++)
            {
                seats[j] += p;
            }
        }

        bool test = true;

        for (int a : seats)
        {
            if (a > C)
            {
                test = false;
                break;
            }
        }
        
        if (test)
        {
            cout << "true" << endl;
        }
        else if (!test)
        {
            cout << "false" << endl;
        }
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
