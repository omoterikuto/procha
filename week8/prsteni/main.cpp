#include <iostream>
#include <vector>

using namespace std;

int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return getGcd(b, a % b);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n, 0);

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        nums[i] = k;
    }

    for (int i = 1; i < n; ++i) {
        int gcd = getGcd(nums[0], nums[i]);
        cout << nums[0] / gcd << "/" << nums[i] / gcd << endl;
    }
}