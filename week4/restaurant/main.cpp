#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, m;

int main() {
    cin >> n;

    vector<int> menus(n);
    for (int i = 0; i < n; ++i) {
        cin >> menus[i];
    }

    cin >> m;
    vector<int> orders(m);
    for (int i = 0; i < m; ++i) {
        cin >> orders[i];
    }


    int maxNum = 0;
    for (int i = 0; i < m; ++i) {
        if (orders[i] > maxNum) {
            maxNum = orders[i];
        }
    }
    vector<vector<int> > dp(n + 1, vector<int>(maxNum + 1, 0));
    dp[0][0] = 1;

    map<int, string> splitStr;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= maxNum; ++j) {
            if (menus[i] <= j) {
                dp[i + 1][j] = dp[i][j] + dp[i + 1][j - menus[i]];
            } else {
                dp[i + 1][j] += dp[i][j];
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        int leftScore = orders[i];
        int result = dp[n][leftScore];
        if (result == 0) {
            cout << "Impossible" << endl;
        } else if (result >= 2) {
            cout << "Ambiguous" << endl;
        } else {
            while (leftScore > 0) {
                for (int j = 0; j < n; ++j) {
                    if (leftScore >= menus[j] && dp[n][leftScore - menus[j]] >= 1) {
                        cout << j + 1 << ends;
                        leftScore -= menus[j];
                        if (leftScore > 0) {
                            cout << " " << ends;
                        }
                        break;
                    }
                }
            }
            cout << endl;
        }
    }
}
