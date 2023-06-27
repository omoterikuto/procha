#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<bool> nums(n + 1, false);

    int total = 1;
    int target = 2;
    while (total <= k) {
        for (int i = 1; target * i <= n; ++i) {
            if (!nums[target * i]) {
                nums[target * i] = true;
                if (total == k) {
                    cout << target * i;
                    return 0;
                }
                ++total;
            }
        }
        for (int i = 3; i <= n; ++i) {
            if (!nums[i]) {
                target = i;
                break;
            }
        }
    }
}