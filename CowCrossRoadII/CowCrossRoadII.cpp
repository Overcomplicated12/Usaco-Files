// CowCrossRoadII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main()
{
	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);
	
    string s;
    cin >> s;

    vector<int> start(26, -1);
    vector<int> end(26, -1);

	for (int i = 0; i < s.size(); i++) {
		if (start[s[i] - 'A'] == -1) {
			start[s[i] - 'A'] = i;
		}
		else {
			end[s[i] - 'A'] = i;
		}
	}

	int ans = 0;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (start[i] < start[j] && start[j] < end[i] && end[i] < end[j])
			{
				ans++;
			}
		}
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
