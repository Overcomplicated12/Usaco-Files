// CowCheckup.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> initial(n);
	vector<int> ideal(n);

	for (int i = 0; i < n; i++)
	{
		cin >> initial[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> ideal[i];
	}

	vector<int> ops(n + 1);
	
	int correct = 0;
	for (int i = 0; i < n; i++)
	{
		if (initial[i] == ideal[i]) correct++;
	}

	for (int i = 0; i < n; i++)
	{
		int l = i;
		int r = i;

		int curr = 0;

		while (l >= 0 && r < n)
		{
			if (initial[l] == ideal[r]) curr++;
			if (initial[r] == ideal[l]) curr++;

			if (initial[l] == ideal[l]) curr--;
			if (initial[r] == ideal[r])curr--;

			ops[curr + correct]++;

			l--;
			r++;
		}

	}

	for (int i = 1; i < n; i++)
	{
		int l = i - 1;
		int r = i;

		int curr = 0;

		while (l >= 0 && r < n)
		{
			if (initial[l] == ideal[r]) curr++;
			if (initial[r] == ideal[l]) curr++;

			if (initial[l] == ideal[l]) curr--;
			if (initial[r] == ideal[r])curr--;

			ops[curr + correct]++;

			l--;
			r++;
		}
	}

	for (int op : ops) cout << op << endl;
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
