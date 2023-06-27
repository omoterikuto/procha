#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortFunc(string a, string b) {
    return a.substr(0, 2) < b.substr(0, 2);
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> nameArr;
        for (int i = 0; i < n; i++) {
            string name;
            cin >> name;
            nameArr.push_back(name);
        }
        stable_sort(nameArr.begin(), nameArr.end(), sortFunc);
        for (int i = 0; i < n; i++) {
            cout << nameArr[i] << endl;
        }
        cout << endl;
    }
}