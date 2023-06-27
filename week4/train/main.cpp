#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int h, l, total = 0;

    for (int i = 0; i < n; ++i) {
        int target;
        cin >> target;
        
        if (i == 0) {
            h = target;
            l = target;
            ++total;
            continue;
        }

        if (target > h) {
            h = target;
            ++total;
        } else if (target < l) {
            l = target;
            ++total;
        }
    }
    cout << total << endl;
};