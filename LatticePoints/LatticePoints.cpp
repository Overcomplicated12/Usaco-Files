// LatticePoints.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
double area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double largerY = min(y1, y3);
    double length = x3 - x1;
    double width = y2 - largerY;
    double area = length * width;

    double h1, b1, h2, b2, h3, b3;
    h1 = abs(y2 - y1);
    b1 = abs(x2 - x1);
    h2 = abs(y2 - y3);
    b2 = abs(x2 - x3);
    h3 = abs(y3 - y1);
    b3 = abs(x3 - x1);

    double a1, a2, a3;
    a1 = (h1 * b1) / 2;
    a2 = (h2 * b2) / 2;
    a3 = (h3 * b3) / 2;

    area = area - a1 - a2 - a3;
    return area;
}
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}
int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int b1 = gcd(abs(x2 - x1), abs(y2 - y1));
    int b2 = gcd(abs(x3 - x2), abs(y3 - y2));
    int b3 = gcd(abs(x1 - x3), abs(y1 - y3));
    int B = b1 + b2 + b3;

    int a = area(x1, y1, x2, y2, x3, y3);

    int I = (a - B / 2 + 1);
    
    cout << (I+B) << endl;

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
