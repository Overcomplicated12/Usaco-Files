#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // Input/output redirection for USACO
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;

    // Read the cow lineup
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Make a sorted copy (what the lineup *should* look like)
    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());

    // Count how many positions differ between current and sorted lineups
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != sorted[i])
            count++;
    }

    // Explanation:
    // If a cow is out of place, we need to count how many cows
    // need to move to restore the sorted order.
    // However, each mismatch is counted twice (once in arr and once in sorted),
    // and we only need the number of swaps involving the one "Bessie".
    // Final answer = mismatches - 1
    cout << count - 1 << endl;

    return 0;
}


