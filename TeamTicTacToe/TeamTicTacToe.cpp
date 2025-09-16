// TeamTicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// function to check a line of 3 chars
void checkLine(char a, char b, char c,
    bool single[26], bool team[26][26]) {
    bool used[26] = { false };
    char line[3] = { a, b, c };

    for (int i = 0; i < 3; i++) {
        used[line[i] - 'A'] = true;   // mark cow as present
    }

    // collect distinct cows
    int count = 0;
    char cows[3];
    for (int i = 0; i < 26; i++) {
        if (used[i]) cows[count++] = 'A' + i;
    }

    if (count == 1) {
        // single winner
        single[cows[0] - 'A'] = true;
    }
    else if (count == 2) {
        // team winner
        char x = cows[0], y = cows[1];
        if (x > y) swap(x, y);
        team[x - 'A'][y - 'A'] = true;
    }
}

int main() {

    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    char grid[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> grid[i][j];
        }
    }

    bool single[26] = { false };      // which cows win alone
    bool team[26][26] = { false };    // which pairs win

    // rows
    for (int i = 0; i < 3; i++) {
        checkLine(grid[i][0], grid[i][1], grid[i][2], single, team);
    }
    // cols
    for (int j = 0; j < 3; j++) {
        checkLine(grid[0][j], grid[1][j], grid[2][j], single, team);
    }
    // diagonals
    checkLine(grid[0][0], grid[1][1], grid[2][2], single, team);
    checkLine(grid[0][2], grid[1][1], grid[2][0], single, team);

    // count results
    int ansSingles = 0, ansTeams = 0;
    for (int i = 0; i < 26; i++) {
        if (single[i]) ansSingles++;
    }
    for (int i = 0; i < 26; i++) {
        for (int j = i + 1; j < 26; j++) {
            if (team[i][j]) ansTeams++;
        }
    }

    cout << ansSingles << "\n" << ansTeams << "\n";
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
