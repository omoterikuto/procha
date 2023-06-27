#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n, m;
int minCost = 1000;

void check(vector<vector<bool> > dp, vector<int> costs, int tuneIndex) {
    if (tuneIndex == m) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i][tuneIndex]) {
            if (tuneIndex == 0) {
                continue;
            }
            if (!dp[i][tuneIndex - 1] || costs[i] > minCost) {
                costs[i] = minCost + 1;

                continue;
            }
            continue;
        }
        costs[i] = -1;
    }
    int min = 1000;
    for (int i = 0; i < n; ++i) {
        if (costs[i] != -1 && min > costs[i]) {
            min = costs[i];
        }
    }
    minCost = min;
    check(dp, costs, ++tuneIndex);
}

int main() {
    cin >> n >> m;

    vector<map<int, bool> > tunes(n);

    for (int i = 0; i < n; ++i) {
        int kn;
        cin >> kn;
        for (int j = 0; j < kn; ++j) {
            int t;
            cin >> t;
            tunes[i][t] = true;
        }
    }


    vector<vector<bool> > dp(n, vector<bool>(m));
    for (int i = 0; i < m; ++i) {
        int tune;
        cin >> tune;
        for (int j = 0; j < n; ++j) {
            if (tunes[j][tune]) {
                dp[j][i] = true;
            }
        }
    }

    vector<int> costs(n, 0);
    check(dp, costs, 0);

    cout << minCost << endl;
}