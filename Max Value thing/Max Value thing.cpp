// Max Value thing.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

const int MOD = 1e9 + 7;

bool compare(string a, string b)
{
    return a + b > b + a;
}
int main()
{
    int n;
    cin >> n;
    
    vector<string> nums(n);

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums[i] = to_string(temp);
    }

    sort(nums.begin(), nums.end(), compare);

    if (nums[0] == "0")
    {
        cout << 0 << endl;
        return 0;
    }

    long long result = 0;

    for (string num : nums)
    {
        for (char c : num)
        {
            result = (result * 10 + (c - '0')) % MOD;
        }
    }

    cout << result << endl;
    return 0;
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
