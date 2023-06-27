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
    int n, m;
    cin >> n >> m;

    typedef pair<int, int> ii;

    vector<vector<int> > grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < (int) line.size(); ++j) {
            grid[i][j] = ctoi(line[j]);
        }
    }

    queue<ii> q;
    q.push(ii(0, 0));

    vector<vector<int> > costs(n, vector<int>(m, -1));
    costs[0][0] = 0;

    while (!q.empty()) {
        ii f = q.front();
        int i = f.first;
        int j = f.second;
        q.pop();

        if (grid[i][j] == 0) {
            continue;
        }

        int c = costs[i][j];
        int jump = grid[i][j];

        if (i + jump < n && (costs[i + jump][j] == -1 || costs[i + jump][j] > c + 1)) {
            q.push(ii(i + jump, j));
            costs[i + jump][j] = c + 1;
        }
        if (j + jump < m && (costs[i][j + jump] == -1 || costs[i][j + jump] > c + 1)) {
            q.push(ii(i, j + jump));
            costs[i][j + jump] = c + 1;
        }
        if (i - jump >= 0 && (costs[i - jump][j] == -1 || costs[i - jump][j] > c + 1)) {
            q.push(ii(i - jump, j));
            costs[i - jump][j] = c + 1;
        }
        if (j - jump >= 0 && (costs[i][j - jump] == -1 || costs[i][j - jump] > c + 1)) {
            q.push(ii(i, j - jump));
            costs[i][j - jump] = c + 1;
        }
    }

    cout << costs[n - 1][m - 1] << endl;


//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << costs[i][j] << " " << ends;
//        }
//        cout << endl;
//    }
}