#include <iostream>
#include <vector>
using namespace std;

int main() {
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            grid[i][j] = s[j] - '0';
        }
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == 1) {
                ans++;   // count this flip

                // flip the entire rectangle (0,0) to (i,j)
                for (int a = 0; a <= i; a++) {
                    for (int b = 0; b <= j; b++) {
                        grid[a][b] = 1 - grid[a][b];  // toggle 0/1
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}
