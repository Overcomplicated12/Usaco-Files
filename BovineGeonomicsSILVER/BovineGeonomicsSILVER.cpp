// BovineGeonomicsSILVER.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <cstring> // for memset

using namespace std;

int encodeChar(char ch) {
    if (ch == 'A') return 0;
    if (ch == 'C') return 1;
    if (ch == 'G') return 2;
    return 3; // 'T'
}

int main() {
    

    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<string> spotted(N), plain(N);
    for (int i = 0; i < N; i++) cin >> spotted[i];
    for (int i = 0; i < N; i++) cin >> plain[i];

    int ans = 0;

    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j < M; j++) {
            for (int k = j + 1; k < M; k++) {
                bool seen[64];
                memset(seen, false, sizeof(seen));

                // encode spotted triplets
                for (int s = 0; s < N; s++) {
                    int a = encodeChar(spotted[s][i]);
                    int b = encodeChar(spotted[s][j]);
                    int c = encodeChar(spotted[s][k]);
                    int code = (a << 4) | (b << 2) | c;
                    seen[code] = true;
                }

                bool ok = true;
                // check plain triplets
                for (int p = 0; p < N && ok; p++) {
                    int a = encodeChar(plain[p][i]);
                    int b = encodeChar(plain[p][j]);
                    int c = encodeChar(plain[p][k]);
                    int code = (a << 4) | (b << 2) | c;
                    if (seen[code]) ok = false;
                }

                if (ok) ans++;
            }
        }
    }

    cout << ans << "\n";
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
