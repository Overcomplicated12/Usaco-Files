// HungryCow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
using ll = long long;
int main()
{
    int N;
    ll T;
    cin >> N >> T;
    
    ll stock = 0;
    ll eaten = 0;
    ll prev = 1;

    for (int i = 0; i < N; i++)
    {
        ll d, b;
        cin >> d >> b;

        ll gap = d - prev;

        if (gap > 0)
        {
            ll use;
            if (stock < gap)  use = stock;
            else  use = gap;

            eaten += use;
            stock -= use;
           
        }
        stock += b;

        prev = d;
    }

    if (prev <= T) {
        long long gap = T - prev + 1;
        long long use = (stock < gap) ? stock : gap;
        eaten += use;
    }

    cout << eaten << endl;
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
