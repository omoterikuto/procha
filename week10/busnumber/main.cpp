#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> counts1;

    for (int i = 1; i * i * i <= n; ++i) {
        counts1.push_back(i * i * i);
    }

    vector<int> counts2(800000, 0);

    for (int i = 0; i < (int) counts1.size(); ++i) {
        for (int j = i + 1; j < (int) counts1.size(); ++j) {
            counts2[counts1[i] + counts1[j]] += 1;
        }
    }

    for (int i = n; i > 0; --i) {
        if (counts2[i] >= 2) {
            cout << i;
            return 0;
        }
    }

    cout << "none";
}