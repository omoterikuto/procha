#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<int, bool> balloons;
int n;
int total = 0;

void shoot(int index, int h, vector<int> heights) {
    int newH = h;
    if (index >= n || h < 1) {
        total++;
        return;
    }

    if (heights[index] == h) {
        balloons[index] = true;
        newH = h - 1;
    }
    shoot(index + 1, newH, heights);
}

int main() {
    cin >> n;
    cin.ignore();

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for (int i = 0; i < n; i++) {
        balloons[i] = false;
    }

    for (int i = 0; i < n; i++) {
        if (!balloons[i]) {
            shoot(i, heights[i], heights);
        }
    }
    cout << total << endl;
}