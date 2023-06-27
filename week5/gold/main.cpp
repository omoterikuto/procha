#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    pair<int, int> playerPosition;
    vector<vector<int> > pass(50, vector<int>(50, 0));

    vector<vector<char> > mx(50, vector<char>(50, 0));
    for (int i = 0; i < m; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < (int) line.size(); ++j) {
            mx[i][j] = line[j];
            if (mx[i][j] == 'P') {
                playerPosition.first = i;
                playerPosition.second = j;
            }
        }
    }
    queue<pair<int, int> > q;
    q.push(playerPosition);

    pass[playerPosition.first][playerPosition.second] = 1;

    int total = 0;

    while (!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        int row = t.first;
        int column = t.second;
        if (mx[row][column] == 'G') {
            ++total;
        }

        if (
                (mx[row + 1][column] == 'T')
                || (mx[row - 1][column] == 'T')
                || (mx[row][column + 1] == 'T')
                || (mx[row][column - 1] == 'T')) {
            continue;
        }

        if (row > 1) {
            if (pass[row - 1][column] != 1 && mx[row - 1][column] != '#') {
                q.emplace(row - 1, column);
                pass[row - 1][column] = 1;
            }
        }
        if (column > 1) {
            if (pass[row][column - 1] != 1 && mx[row][column - 1] != '#') {
                q.emplace(row, column - 1);
                pass[row][column - 1] = 1;
            }
        }
        if (row < m - 2) {
            if (pass[row + 1][column] != 1 && mx[row + 1][column] != '#') {
                q.emplace(row + 1, column);
                pass[row + 1][column] = 1;
            }
        }
        if (column < n - 2) {
            if (pass[row][column + 1] != 1 && mx[row][column + 1] != '#') {
                q.emplace(row, column + 1);
                pass[row][column + 1] = 1;
            }
        }
    }

    cout << total << endl;
}