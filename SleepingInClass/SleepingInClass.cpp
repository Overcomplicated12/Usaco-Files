// SleepingInClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int count_sols(int n) {
    vector<int> elsie(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> elsie[i];
        total += elsie[i];
    }

    for (int i = 0; i <= total; i++) {
        if (i != 0 && total % i != 0) {
            continue;
        }

        int curr_sum = 0;
        bool working = true;

        for (int h : elsie) {
            curr_sum += h;
            if (curr_sum > i) {
                working = false;
                break;
            }
            else if (curr_sum == i) {
                curr_sum = 0;
            }
        }

        if (working) {
            if (i == 0) {
                return 0;
            }
            else {
                return n - total / i;
                break;
            }
            
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << count_sols(n) << endl;
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
