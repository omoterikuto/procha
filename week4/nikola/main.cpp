#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> costs;
vector<vector<int> > dp(1001, vector<int>(1001, -1));

inline int check(int sqIndex, int beforeJump) {
    if (dp[sqIndex][beforeJump] != -1) {
        return dp[sqIndex][beforeJump];
    }

    if (sqIndex == n - 1) {
        dp[sqIndex][beforeJump] = costs[sqIndex];
        return costs[sqIndex];
    }

    int a = 1000000000;
    int b = 1000000000;
    if (sqIndex - beforeJump >= 0 && beforeJump != 0) {
        a = check(sqIndex - beforeJump, beforeJump) + costs[sqIndex];
    }

    if (sqIndex + beforeJump + 1 < n) {
        b = check(sqIndex + beforeJump + 1, beforeJump + 1) + costs[sqIndex];
    }

    if (a < b) {
        dp[sqIndex][beforeJump] = a;
    } else {
        dp[sqIndex][beforeJump] = b;
    }

    return dp[sqIndex][beforeJump];
}

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        costs.push_back(temp);
    }

    cout << check(0, 0) - costs[0] << endl;
};

