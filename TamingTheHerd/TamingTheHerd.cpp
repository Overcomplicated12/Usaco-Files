// TamingTheHerd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//





#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    // inputs
    int N;
    cin >> N;
    vector<int> log;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        log.push_back(temp);
    }
    // if first is not 0 or -1 output -1
    if (log[0] > 0)
    {
        cout << -1 << endl;
        return 0;
    }
    log[0] = 0;
    // check for all other conditions
    int t = -1;
    int req = 0;
    int may = 0;

    for (int i = N - 1; i >= 0; i--)
    {
        //impossible case ex. {0, 1, 3}
        if (t != log[i] && t != -1 && log[i] != -1)
        {
            cout << -1 << endl;
            return 0;
        }
        // set t to the current number if it doesn't hold anything currently
        if (t == -1)
        {
            t = log[i];
        }
        // if there is a missing value set it to the predicted value
        if (log[i] == -1)
        {
            log[i] = t;
        }
        // if it has been 0 days since the last breakout then there was definitely a breakout on that day
        if (log[i] == 0)
        {
            req++;
        }
        // if the value still cannot be determined then maybe there was a breakout on that day
        if (log[i] == -1)
        {
            may++;
        }
        // subtract one from t to predict next value.
        if (t != -1)
        {
            t--;
        }
    }
    //output
    cout << req << ' ' << req + may << endl;
    return 0;
}


