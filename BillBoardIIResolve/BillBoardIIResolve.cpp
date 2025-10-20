// BillBoardIIResolve.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int main()
{
    freopen("billboard.in", "r", stdin); freopen("billboard.out", "w", stdout);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int area_lawnmower = (x2 - x1) * (y2 - y1);

    if (x4 >= x2 and x3 <= x1 and y3 <= y1 and y4 >= y2)
    {
        cout << 0 << endl;
    }
    else if (x3 <= x1 && x4 >= x2)
    {
        int yl = max(y1, y3);
        int yr = min(y2, y4);
        if (y2 > y4 && y1 < y3)
        {
            cout << area_lawnmower << endl;
        }
        else if (yr > yl)
            cout << area_lawnmower - (x2 - x1) * (yr - yl) << endl;

        else
            cout << area_lawnmower << endl;
    }
    else if (y3 <= y1 && y4 >= y2)
    {
        int xl = max(x1, x3);
        int xr = min(x2, x4);
        if (x2 > x4 && x1 < x3)
        {
            cout << area_lawnmower << endl;
        }
        else if (xr > xl)
            cout << area_lawnmower - (xr - xl) * (y2 - y1) << endl;


        else
            cout << area_lawnmower << endl;
    }
    else
    {

        cout << area_lawnmower << endl;
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
