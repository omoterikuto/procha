#include <iostream>
#include <vector>

using namespace std;
vector<char> strs = {'I', 'C', 'P', 'C', 'A', 'S', 'I', 'A', 'S', 'G'};
vector<pair<int, int> > moves = {
        {1,  2},
        {1,  -2},
        {2,  1},
        {2,  -1},
        {-1, 2},
        {-1, -2},
        {-2, 1},
        {-2, -1},
};
int n;

vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int>()));

inline bool check(vector<vector<char> > cells, pair<int, int> position, int strIndex) {
    if (strIndex == strs.size()) {
        return true;
    }

    for (int i = 0; i < dp[position.first][position.second].size(); ++i) {
        if (strIndex == i) {
            return false;
        }
    }

    dp[position.first][position.second].push_back(strIndex);

    for (int i = 0; i < 8; ++i) {
        int nextRow = position.first + moves[i].first;
        int nextCol = position.second + moves[i].second;
        if (nextRow >= 0 && nextCol >= 0
            && nextRow < n && nextCol < n
            && strs[strIndex] == cells[nextRow][nextCol]
            && check(cells, {nextRow, nextCol}, strIndex + 1)) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> n;

    string line;
    cin >> line;

    vector<vector<char> > cells(n, vector<char>(n));

    vector<pair<int, int> > firstPosition;
    for (int i = 0; i < n * n; ++i) {
        int row = i / n;
        int col = i - row * n;
        if (line[i] == 'I') {
            firstPosition.emplace_back(row, col);
        }
        cells[row][col] = line[i];
    }
    bool no = true;
    for (const auto &i: firstPosition) {
        if (check(cells, i, 1)) {
            cout << "YES" << endl;
            no = false;
            break;
        }
    }
    if (no) {
        cout << "NO" << endl;
    }
}


