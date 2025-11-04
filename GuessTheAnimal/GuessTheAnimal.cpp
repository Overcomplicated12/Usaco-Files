// GuessTheAnimal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);

    int N; cin >> N;
    vector<vector<string>> characteristics(N);

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;
        int K; cin >> K;
        for (int j = 0; j < K; j++)
        {
            string charac; cin >> charac;
            characteristics[i].push_back(charac);

        }
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int common = 0;
            for (string charac1 : characteristics[i])
            {
                for (string charac2 : characteristics[j])
                {
                    if (charac1 == charac2)
                    {
                        common++;
                    }
                }
            }
            ans = max(ans, common);
        }
    }

    cout << ans+1 << endl;
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
