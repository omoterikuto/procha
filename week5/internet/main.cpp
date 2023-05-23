#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > connect(n + 1, vector<int>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        connect[a].push_back(b);
        connect[b].push_back(a);
    }

    queue<int> q;
    map<int, bool> check;
    check[1] = true;
    q.push(1);

    while (!q.empty()) {
        int target = q.front();
        q.pop();

        for (auto i: connect[target]) {
            if (!check[i]) {
                check[i] = true;
                q.push(i);
            }
        }
    }

    bool notAll = false;
    for (int i = 1; i <= n; ++i) {
        if (!check[i]) {
            notAll = true;
            cout << i << endl;
        }
    }
    if (!notAll) {
        cout << "Connected" << endl;
    }
};