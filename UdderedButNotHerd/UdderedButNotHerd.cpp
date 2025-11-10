// UdderedButNotHerd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int main()
{
    vector<char> cowphabet(26);
    for (int i = 0; i < 26; i++)
    {
        cin >> cowphabet[i];
    }


    string word;
    cin >> word;

    vector<int> pos(26);
    for (int i = 0; i < 26; i++)
    {
        pos[cowphabet[i] - 'a'] = i;
    }


    int ans = 1;
    for (int i = 0; i < word.size() - 1; i++)
    {
        if (pos[word[i+1] -'a'] <= pos[word[i] - 'a']) ans++;
    }
    
    cout << ans << endl;
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
