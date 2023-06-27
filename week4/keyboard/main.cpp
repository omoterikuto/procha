#include <iostream>
#include <vector>
#include <map>

using namespace std;
int n, m;
int total = 1000;

// indexに対しての最小コスト
vector<int> dp2(1000, 1000);

void
check(vector<map<int, bool> > dp, vector<int> tunes, int instrumentIndex, int tuneIndex,
      int num) {
    if (total < num) {
        return;
    }
    if (tuneIndex == m) {
        if (num < total) {
            total = num;
        }
        return;
    }
    if (dp2[tuneIndex] < num) {
        return;
    }

    int tune = tunes[tuneIndex];

    if (dp[instrumentIndex][tune]) {
        dp2[tuneIndex] = num;
        check(dp, tunes, instrumentIndex, ++tuneIndex, num);
    } else {
        for (int i = 0; i < n; ++i) {
            if (i == instrumentIndex) {
                continue;
            }
            dp2[tuneIndex] = num;
            check(dp, tunes, i, ++tuneIndex, ++num);

        }
    }
}

int main() {
    cin >> n >> m;

    vector<map<int, bool> > dp(n);

    for (int i = 0; i < n; ++i) {
        int kn;
        cin >> kn;
        for (int j = 0; j < kn; ++j) {
            int t;
            cin >> t;
            dp[i][t] = true;
        }
    }
    vector<int> tunes(m);
    for (int i = 0; i < m; ++i) {
        cin >> tunes[i];
    }

    for (int i = 0; i < n; ++i) {
        check(dp, tunes, i, 0, 0);
    }

    cout << total << endl;
}