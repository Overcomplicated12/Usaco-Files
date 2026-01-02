#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

vector<string> canvas;
int N, U;

int group_cost(int r, int c, int N) {
    vector<pair<int, int>> cells = {
        {r, c},
        {N - 1 - r, c},
        {r, N - 1 - c},
        {N - 1 - r, N - 1 - c}
    };

    int hash = 0, dot = 0;
    for (auto& p : cells) {
        int x = p.first;
        int y = p.second;
        if (canvas[x][y] == '#') hash++;
        else dot++;
    }
    return min(hash, dot);
}

int scan() {
    int moves = 0;
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N / 2; j++) {
            moves += group_cost(i, j, N);
        }
    }
    return moves;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> U;
    canvas.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> canvas[i];
    }

    int moves = scan();
    cout << moves << "\n";

    for (int i = 0; i < U; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--; // convert to 0-based

        // canonical representative of the 4-cell group
        int gr = min(r, N - 1 - r);
        int gc = min(c, N - 1 - c);

        // remove old group contribution
        moves -= group_cost(gr, gc, N);

        // toggle the cell
        canvas[r][c] = (canvas[r][c] == '#') ? '.' : '#';

        // add new group contribution
        moves += group_cost(gr, gc, N);

        cout << moves << "\n";
    }

    return 0;
}
