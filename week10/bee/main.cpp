#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int h, n, m;
    cin >> h >> n >> m;

    if (h == 0) {
        cout << 0;
        return 0;
    }

    vector<vector<int> > gird(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char hh;
            cin >> hh;
            if (hh == '.') {
                gird[i][j] = 0;
            } else {
                gird[i][j] = 1;
            }
        }
    }

    typedef pair<int, int> ii;
    vector<ii> directionOdd;

    directionOdd.push_back(ii(1, -1));
    directionOdd.push_back(ii(1, 0));
    directionOdd.push_back(ii(0, -1));
    directionOdd.push_back(ii(0, 1));
    directionOdd.push_back(ii(-1, -1));
    directionOdd.push_back(ii(-1, 0));

    vector<ii> directionEven;

    directionEven.push_back(ii(1, 0));
    directionEven.push_back(ii(1, 1));
    directionEven.push_back(ii(0, -1));
    directionEven.push_back(ii(0, 1));
    directionEven.push_back(ii(-1, 0));
    directionEven.push_back(ii(-1, 1));

    vector<int> adjacent;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (gird[i][j] == 1) {
                continue;
            }
            gird[i][j] = 1;
            queue<ii> q;
            q.push(ii(i, j));

            int seq = 1;

            while (!q.empty()) {
                int ia = q.front().first;
                int ja = q.front().second;
                q.pop();
                for (int k = 0; k < 6; ++k) {
                    int nn, mm;
                    if (ia % 2 == 0) {
                        nn = directionOdd[k].first;
                        mm = directionOdd[k].second;
                    } else {
                        nn = directionEven[k].first;
                        mm = directionEven[k].second;
                    }
                    if (nn + ia >= 0 && nn + ia < n && mm + ja >= 0 && mm + ja < m && gird[nn + ia][mm + ja] == 0) {
                        seq += 1;
                        gird[nn + ia][mm + ja] = 1;
                        q.push(ii(nn + ia, mm + ja));
                    }
                }
            }
            adjacent.push_back(seq);
        }
    }

    sort(adjacent.begin(), adjacent.end());


    int remain = h;
    int total = 0;
    for (int i = (int) adjacent.size() - 1; i >= 0; --i) {
        remain -= adjacent[i];
        ++total;
        if (remain <= 0) {
            cout << total;
            return 0;
        }
    }
}