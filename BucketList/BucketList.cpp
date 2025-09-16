// BucketList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_TIME = 1000;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> start(n), end(n), buckets(n);
    for (int i = 0; i < n; i++) {
        cin >> start[i] >> end[i] >> buckets[i];
    }

    // The maximum number of buckets needed
    int max_buckets = 0;

    /*
     * For each possible time, check how many buckets are needed at that time
     * and update the maximum accordingly
     */
    for (int t = 1; t <= MAX_TIME; t++) {
        int curr_buckets = 0;
        for (int i = 0; i < n; i++) {
            if (start[i] <= t && t <= end[i]) {
                curr_buckets += buckets[i];
            }
        }
        max_buckets = max(max_buckets, curr_buckets);
    }

    cout << max_buckets << endl;
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
