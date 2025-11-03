#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int main()
{
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> sorted(arr);
    sort(sorted.begin(), sorted.end());

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != sorted[i]) count++;
    }

    cout << count - 1 << endl;
}

