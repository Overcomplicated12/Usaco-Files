// DontBeLast.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include<map>

using namespace std;
int main()
{
   freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int N;
    cin >> N;

    map<string, int>raw;
    for (int i = 0; i < N; i++)
    {
        string a;
        int b;
        cin >> a >> b;
        raw[a] += b;
    }

    vector<pair<int, string>>cows;
    for (pair<string, int> t : raw) { cows.push_back({ t.second, t.first }); }
    sort(cows.begin(), cows.end());

    int lowest = cows[0].first;

    int second = -1;
    if (cows.size() == 1)
    {
        cout << cows[0].second << endl;
        return 0;
    }
    for (auto a : cows)
    {
        if (a.first != lowest)
        {
            second = a.first;
            break;

        }
    }
    if (second == -1)
    {
        cout << "Tie" << endl;
        return 0;
    }

    vector<string> names;
    for (auto& p : cows)
        if (p.first == second)
            names.push_back(p.second);

    if (names.size() == 1)
    {
        cout << names[0] << endl;
    }
    else cout << "Tie" << endl;

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
