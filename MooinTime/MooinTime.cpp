// MooinTime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// encode a triple into a number 0..17575
int enc(char a, char b, char c) {
    return (a - 'a') * 26 * 26 + (b - 'a') * 26 + (c - 'a');
}

// check if a triple is a moo: xyy where x != y
bool is_moo(char a, char b, char c) {
    return (b == c) && (a != b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, F;
    cin >> N >> F;
    string s;
    cin >> s;

    const int M = 26 * 26 * 26;
    vector<int> cnt(M, 0), best(M, 0);

    // 1) Count moos in the original string
    for (int i = 0; i + 2 < N; i++) {
        if (is_moo(s[i], s[i + 1], s[i + 2])) {
            cnt[enc(s[i], s[i + 1], s[i + 2])]++;
        }
    }
    best = cnt; // zero-change case

    // 2) Try all one-character changes
    for (int i = 0; i < N; i++) {
        char oldc = s[i];

        for (char nc = 'a'; nc <= 'z'; nc++) {
            if (nc == oldc) continue;

            map<int, int> delta; // small: at most a few entries

            for (int k = i - 2; k <= i; k++) {
                if (k < 0 || k + 2 >= N) continue;

                char a = s[k], b = s[k + 1], c = s[k + 2];

                // old triple
                if (is_moo(a, b, c)) {
                    delta[enc(a, b, c)]--;
                }

                // new triple
                if (k == i) a = nc;
                else if (k + 1 == i) b = nc;
                else if (k + 2 == i) c = nc;

                if (is_moo(a, b, c)) {
                    delta[enc(a, b, c)]++;
                }
            }

            for (auto& p : delta) {
                int id = p.first;
                best[id] = max(best[id], cnt[id] + p.second);
            }
        }
    }

    // 3) Output results
    vector<string> ans;
    for (char a = 'a'; a <= 'z'; a++) {
        for (char b = 'a'; b <= 'z'; b++) {
            if (a == b) continue;
            int id = enc(a, b, b);
            if (best[id] >= F) {
                ans.push_back(string() + a + b + b);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto& m : ans) cout << m << "\n";
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
