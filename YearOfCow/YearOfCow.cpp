// YearOfCow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    

    // zodiac cycle
    vector<string> zodiac = { "Ox","Tiger","Rabbit","Dragon","Snake","Horse",
                             "Goat","Monkey","Rooster","Dog","Pig","Rat" };
    map<string, int> zmap;
    for (int i = 0; i < 12; i++) zmap[zodiac[i]] = i;

    int N;
    cin >> N;
    map<string, long long> birth;
    birth["Bessie"] = 0; // Bessie = year 0 (Ox)

    for (int i = 0; i < N; i++) {
        string name, tmp, dir, animal, tmp2, tmp3, base;
        // Example: "Mildred born in previous Dragon year from Bessie"
        cin >> name >> tmp >> tmp2 >> dir >> animal >> tmp3 >> tmp3 >> base;

        long long baseYear = birth[base];
        int baseZ = ((baseYear % 12) + 12) % 12;
        int targetZ = zmap[animal];
        long long diff;

        if (dir == "next") {
            diff = (targetZ - baseZ + 12) % 12;
            if (diff == 0) diff = 12;
            birth[name] = baseYear + diff;
        }
        else { // "previous"
            diff = (baseZ - targetZ + 12) % 12;
            if (diff == 0) diff = 12;
            birth[name] = baseYear - diff;
        }
    }

    cout << abs(birth["Elsie"]) << "\n";

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
