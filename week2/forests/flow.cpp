#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > time(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> time[i][j];
        }
    }
    int total = 1;
    while (true) {
        bool work = false;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                // 前のラベルのswatherが終わってない時
                if (i != 0 && time[i - 1][j] != 0) {
                    continue;
                }
                // 前のステージが終わってない時
                if (j != 0 && time[i][j - 1] != 0) {
                    continue;
                }
                if (time[i][j] != 0) {
                    work = true;
                    time[i][j]--;
                    if (j == m - 1 && time[i][j] == 0) {
                        cout << total << ends;
                        if (i != n - 1) {
                            cout << ' ' << ends;
                        }
                    }
                }
            }
        }
        if (!work) {
            break;
        }
        total++;
    }
}