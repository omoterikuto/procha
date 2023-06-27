#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    string line1, line2;
    cin >> line1 >> line2;

    int sameCount = 0;
    int n = (int) line1.size();

    for (int i = 0; i < n; ++i) {
        if (line1[i] == line2[i]) {
            ++sameCount;
        }
    }

    cout << n - abs(sameCount - k) << endl;
}

