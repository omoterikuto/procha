#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector<int> i, vector<int> j) {
    return i[0] < j[0];
}


int main() {
    int n;
    cin >> n;

    vector<vector<int> > inputs;
    for (int i = 0; i < n; ++i) {
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        vector<int> tmp(3, 0);
        tmp[0] = y;
        tmp[1] = x1;
        tmp[2] = x2 - 1;
        inputs.push_back(tmp);
    }

    sort(inputs.begin(), inputs.end(), comp);

    int total = 0;

    total += (inputs[0][0] * 2);

    for (int i = 1; i < n; ++i) {
        int y = inputs[i][0];
        int x1 = inputs[i][1];
        int x2 = inputs[i][2];
        bool ok1 = false;
        bool ok2 = false;
        for (int j = i - 1; 0 <= j; --j) {
            int uy = inputs[j][0];
            int ux1 = inputs[j][1];
            int ux2 = inputs[j][2];
            if (!ok1 && ux1 <= x1 && x1 <= ux2) {
                total += (y - uy);
                ok1 = true;
            }
            if (!ok2 && ux1 <= x2 && x2 <= ux2) {
                total += (y - uy);
                ok2 = true;
            }
            if (ok1 && ok2) {
                break;
            }
        }
        if (!ok1) {
            total += y;
        }
        if (!ok2) {
            total += y;
        }
    }

    cout << total;
}