#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n, m;
map<int, bool> checked;

void check(int target, vector<vector<int> > mx) {
    checked[target] = true;
    for (int i = 1; i <= n; ++i) {
        if (mx[target][i] == 1 && !checked[i]) {
            check(i, mx);
        }
    }
}

int main() {
    cin >> n >> m;

    vector<vector<int> > mx(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        mx[a][b] = 1;
        mx[b][a] = 1;
    }

    check(1, mx);

    bool notAll;
    for (int i = 1; i <= n; ++i) {
        if (!checked[i]) {
            notAll = true;
            cout << i << endl;
        }
    }
    if (!notAll) {
        cout << "Connected" << endl;
    }
}