// BillBoardIIResolve.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    int x1, y1, x2, y2; // billboard
    int x3, y3, x4, y4; // covering rect (e.g., truck)
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    int area = (x2 - x1) * (y2 - y1);

    // If fully covered
    if (x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2) {
        cout << 0 << '\n';
        return 0;
    }

    // Overlap rectangle
    int w = max(0, min(x2, x4) - max(x1, x3));
    int h = max(0, min(y2, y4) - max(y1, y3));

    // Subtract only if the cover spans the full width OR the full height.
    // (This is the rule for Blocked Billboard I.)
    if ((x3 <= x1 && x4 >= x2) && h > 0) {
        cout << area - (x2 - x1) * h << '\n';
    }
    else if ((y3 <= y1 && y4 >= y2) && w > 0) {
        cout << area - w * (y2 - y1) << '\n';
    }
    else {
        cout << area << '\n';
    }
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
