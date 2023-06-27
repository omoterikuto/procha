#include <iostream>
#include <vector>

using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    vector<vector<string>> parkMap(r, vector<string>(c));

    for (int i = 0; i < r; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < c; j++) {
            parkMap[i][j] = line[j];
        }
    }

    vector<int> count(4);

    for (int i = 0; i < r - 1; i++) {
        for (int j = 0; j < c - 1; j++) {
            if (parkMap[i][j] == "#") {
                continue;
            }
            vector<string> target{parkMap[i][j], parkMap[i + 1][j], parkMap[i][j + 1], parkMap[i + 1][j + 1]};
            int xCount = 0;
            bool noPark = false;
            for (int k = 0; k < 4; k++) {
                if (target[k] == "X") {
                    xCount += 1;
                } else if (target[k] == "#") {
                    noPark = true;
                    break;
                }
            }
            if (noPark) {
                continue;
            }
            count[xCount] += 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        cout << count[i] << endl;
    }
}