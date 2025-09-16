// Base.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <algorithm>



using namespace std;
int to_base_10(int base, const string& num) {
	return (num[0] - '0') * base * base + (num[1] - '0') * base + (num[2] - '0');
}

int main() {
	freopen("whatbase.in", "r", stdin);
	freopen("whatbase.out", "w", stdout);

	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		string a, b;
		cin >> a >> b;

		
		int y = 10;
		for (int x = 10; x <= 15000; x++) {
			const int cur = to_base_10(x, a);

			
			while (to_base_10(y, b) < cur) { y++; }

			if (y <= 15000 && to_base_10(y, b) == cur) {
				 cout << x << ' ' << y << '\n';
				break;
			}
		}
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
