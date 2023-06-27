#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return 0;
}

int main() {
    int h, w;
    while (cin >> h >> w) {
        if (h == 0 && w == 0) {
            break;
        }
        typedef pair<int, int> ii;

        vector<vector<int> > digits(h, vector<int>(w, 0));
        for (int i = 0; i < h; ++i) {
            string line;
            cin >> line;
            for (int j = 0; j < (int) line.size(); ++j) {
                digits[i][j] = ctoi(line[j]);
            }
        }

        queue<ii> q;
        vector<vector<int> > costs(h, vector<int>(w, -1));

        vector<vector<pair<int, int> > > trace(h, vector<pair<int, int> >(w));

        for (int i = 0; i < w; ++i) {
            costs[0][i] = digits[0][i];
        }

        for (int ia = 0; ia < w; ++ia) {
            q.push(ii(0, ia));

            while (!q.empty()) {
                ii f = q.front();
                int i = f.first;
                int j = f.second;
                q.pop();
                if (i == h - 1) {
                    continue;
                }

                int c = costs[i][j];

                for (int k = -1; k <= 1; ++k) {
                    for (int l = -1; l <= 1; ++l) {
                        if (i + k >= 0 && j + l >= 0 && i + k < h && j + l < w
                            && (costs[i + k][j + l] == -1 || costs[i + k][j + l] > c + digits[i + k][j + l])) {
                            q.push(ii(i + k, j + l));
                            costs[i + k][j + l] = c + digits[i + k][j + l];
                            trace[i + k][j + l] = ii(i, j);
                        }
                    }
                }
            }
        }

        vector<vector<bool> > route(h, vector<bool>(w, false));
        int min = -1;
        int minCol = 0;
        for (int i = 0; i < w; ++i) {
            if (min == -1 || min > costs[h - 1][i]) {
                min = costs[h - 1][i];
                minCol = i;
            }
        }
        int nextRow = h - 1;
        int nextCol = minCol;
        while (true) {
            route[nextRow][nextCol] = true;
            if (nextRow == 0) {
                break;
            }
            ii xy = trace[nextRow][nextCol];
            nextRow = xy.first;
            nextCol = xy.second;
        }

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (route[i][j]) {
                    cout << " ";
                } else {
                    cout << digits[i][j];
                }
            }
            cout << endl;
        }
        cout << endl;
    }
}