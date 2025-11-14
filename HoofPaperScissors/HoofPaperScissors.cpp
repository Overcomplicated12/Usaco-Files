// HoofPaperScissors.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
bool win(char a, char b)
{
    if (a == 'H' && b == 'S') return true;
    if (a == 'S' && b == 'P') return true;
    if (a == 'P' && b == 'H') return true;
    return false;
}
int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, int>> games(n);
    for (int i = 0; i < n; i++)
    {
        cin >> games[i].first >> games[i].second;
    }

    vector<char> perm = { 'H','P','S' };
    int best = 0;
    sort(perm.begin(), perm.end());
    do
    {
        int num = 0;
        for (auto g : games)
        {
            char a = perm[g.first - 1];
            char b = perm[g.second - 1];
            if (win(a, b)) num++;
        }
        best = max(best, num);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << best << endl;
    return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
