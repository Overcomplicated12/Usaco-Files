#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> outdeg(N + 1, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;   // conveyor belt a -> b
        outdeg[a]++;    // outgoing edge from a
    }

    int candidate = -1;
    int sinkCount = 0;

    for (int i = 1; i <= N; i++) {
        if (outdeg[i] == 0) {
            sinkCount++;
            candidate = i;
        }
    }

    if (sinkCount == 1)
        cout << candidate << "\n";
    else
        cout << -1 << "\n";

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
