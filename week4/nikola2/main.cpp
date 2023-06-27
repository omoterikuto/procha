#include <iostream>
#include <vector>

using namespace std;

int n;

vector<vector<int> > check(vector<vector<int> > dp, vector<int> costs) {
    int lastCheckIndex = 1;
    for (int jump = 1; lastCheckIndex < n; ++jump) {
        for (int i = lastCheckIndex; i < lastCheckIndex + jump && i < n; ++i) {
            if (jump != 1) {
                dp[jump][i] = dp[jump - 1][i - jump] + costs[i];
            } else {
                dp[jump][i] = costs[i];
            }
        }
        for (int i = lastCheckIndex - 1; i >= 0; --i) {
            dp[jump][i] = dp[jump][i + jump] + costs[i];
        }
        lastCheckIndex += jump;
    }
    return dp;
}

int main() {
    cin >> n;

    vector<vector<int> > dp(n + 1, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        dp[0][i] = 1000000000;
    }

    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> costs[i];
    }

    vector<vector<int> > ans;
    ans = check(dp, costs);

    int min = 1000000000;
    for (int i = 0; i < n; ++i) {
        if (ans[i][n - 1] > 0 && min > ans[i][n - 1]) {
            min = ans[i][n - 1];
        }
    }

    cout << min << endl;
};

