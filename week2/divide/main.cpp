#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    cin >> n;
    cin.ignore();

    string m;
    cin >> m;

    if (m == "1") {
        cout << n << ends;
        return 0;
    }
    string ans;

    string strZero = "0";

    int zeroCount = 0;
    for (int i = 0; (i = m.find(strZero, i)) != std::string::npos; i++) {
        zeroCount++;
    }
    int nSize = n.size();
    if (nSize > zeroCount) {
        for (int i = 0; i < nSize; i++) {
            ans += n[i];
            if (i == nSize - zeroCount - 1) {
                ans += '.';
            }
        }
    } else {
        ans += '0';
        ans += '.';
        for (int i = 0; i < zeroCount - nSize; i++) {
            ans += '0';
        }
        for (int i = 0; i < nSize; i++) {
            ans += n.substr(i, 1);
        }
    }

    int omitCount = 0;

    if (nSize < zeroCount) {
        for (int i = zeroCount - nSize + 3; i > zeroCount - nSize; i--) {
            if (ans[i] == '0') {
                omitCount++;
                continue;
            }
            break;
        }
    } else {
        for (int i = nSize; i > nSize - zeroCount; i--) {
            if (ans[i] == '0') {
                omitCount++;
                continue;
            }
            break;
        }
    }

    if (omitCount != 0) {
        if (omitCount == zeroCount) {
            cout << ans.substr(0, ans.size() - omitCount - 1);
        } else {
            cout << ans.substr(0, ans.size() - omitCount);
        }
    } else {
        cout << ans << ends;
    }
}
