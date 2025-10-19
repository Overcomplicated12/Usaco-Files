//Problem: 
// 
//Remove one element(b01)
//Given an array of integers, report whether it is possible to remove one element so that the array is
//strictly increasing.
//Input(from terminal / stdin)
// The first line contains integer 𝑄, the number of queries, 1 ≤ 𝑄 ≤ 100.
// For each query, the first line contains integer 𝑁, the number of integers in the array, 1 ≤ 𝑁 ≤
//1000.
// The second line contains the 𝑁 integers, all in the range[-1000, 1000].
//Output(to terminal / stdout)
// Report the number of queries where the answer is “Yes”.
//Sample input
//2
//5
//1 2 10 5 7
//4
//2 3 1 2
//Sample output
//1
//The answers to the two queries are “Yes” and “No”.

#include <iostream>
#include <vector>
using namespace std;

bool increasing(vector<int> a)
{
    int n = a.size(), count = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] <= a[i - 1])
        {
            count++;
            if (i > 1 && a[i] <= a[i - 2])
                a[i] = a[i - 1];
        }
    }
    return count <= 1;
}
int main()
{

    int N; cin >> N;

    int ans = 0;
    while (N--)
    {
        int a; cin >> a;
        vector<int> arr(a);
        for (int i = 0; i < a; i++)
        {
            cin >> arr[i];
        }

        if (increasing(arr)) ans++;


    }

    cout << ans << endl;
}