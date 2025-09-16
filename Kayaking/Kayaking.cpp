// Kayaking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	N *= 2;

	vector<int> people(N);
	for (int& p : people) { cin >> p; }
	sort(people.begin(), people.end());

	int min_instability = INT32_MAX;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			vector<int> new_people;
			for (int p = 0; p < N; p++) {
				if (p != i && p != j) { new_people.push_back(people[p]); }
			}

			int total_instability = 0;
			for (int p = 0; p < N - 2; p += 2) {
				total_instability += new_people[p + 1] - new_people[p];
			}
			min_instability = min(min_instability, total_instability);
		}
	}
	cout << min_instability << endl;
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
