// lemmetest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
	int test_num;
	cin >> test_num;
	for (int t = 0; t < test_num; t++) {
		int n;
		cin >> n;
		vector<int> elsie_log = vector<int>(n);
		int log_sum = 0;
		for (int& h : elsie_log) {
			cin >> h;
			log_sum += h;
		}

		// Try all possible number of hours after modification
		for (int num_hours = 0; num_hours <= log_sum; num_hours++) {
			if (num_hours != 0 && log_sum % num_hours != 0) {
				// The sum must be divisible by num_hours
				continue;
			}

			// Check if num_hours leads to a valid answer
			int curr_sum = 0;  // The current number of hours Elsie's logging
			bool valid = true;
			for (int h : elsie_log) {
				curr_sum += h;
				if (curr_sum > num_hours) {
					valid = false;  // curr_sum can't exceed num_hours
					break;
				}
				else if (curr_sum == num_hours) {
					curr_sum = 0;
				}
			}

			if (valid) {
				if (num_hours == 0) {
					// Handle the edge case where num_hours is 0
					cout << 0 << '\n';
				}
				else {
					// sum/num_hours is the total # of classes AFTER modifying
					cout << n - log_sum / num_hours << '\n';
				}
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
