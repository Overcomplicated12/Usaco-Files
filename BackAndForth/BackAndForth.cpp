// BackAndForth.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

set<int> possible;

void get_possible(int day, int a_tank, vector<int> a_buckets, int b_tank,
	vector<int> b_buckets) {
	// Last day, add the amount of milk in the first tank.
	if (day == 4) {
		possible.insert(a_tank);
		return;
	}
	// This transfers every possible bucket from barn x to barn y.
	for (int i = 0; i < a_buckets.size(); i++) {
		// Bucket to transfer.
		int t = a_buckets[i];
		// Creates a new copy of available buckets, and transfers the ith one.
		vector<int> new_a = a_buckets;
		new_a.erase(begin(new_a) + i);
		vector<int> new_b = b_buckets;
		new_b.push_back(t);

		// Recursively call the function with the new buckets and tank amounts.
		get_possible(day + 1, b_tank + t, new_b, a_tank - t, new_a);
	}
}

int main() {
	freopen("backforth.in", "r", stdin);
	freopen("backforth.out", "w", stdout);
	vector<int> a(10);
	for (int& i : a) { cin >> i; }
	vector<int> b(10);
	for (int& i : b) { cin >> i; }

	get_possible(0, 1000, a, 1000, b);
	cout << possible.size() << endl;
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
