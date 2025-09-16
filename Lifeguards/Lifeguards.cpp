// Lifeguards.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string spotty[100], plain[100];

    
    for (int i = 0; i < N; i++) {
        cin >> spotty[i];
    }

    // Input the genomes of plain cows
    for (int i = 0; i < N; i++) {
        cin >> plain[i];
    }

    int count = 0;

    // Check each position in the genome
    for (int j = 0; j < M; j++) {
        set<char> spotty_set, plain_set;

        // Collect characters in position j for spotty cows
        for (int i = 0; i < N; i++) {
            spotty_set.insert(spotty[i][j]);
        }

        // Collect characters in position j for plain cows
        for (int i = 0; i < N; i++) {
            plain_set.insert(plain[i][j]);
        }

        // Check if the two sets are disjoint
        bool is_disjoint = true;
        for (char c : spotty_set) {
            if (plain_set.count(c)) {
                is_disjoint = false;
                break;
            }
        }

        if (is_disjoint) {
            count++;
        }
    }

    // Output the number of positions that could explain spottiness
    cout << count << endl;

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
