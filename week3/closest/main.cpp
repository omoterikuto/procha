#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, m, caseCount = 0;
    while (true) {
        caseCount += 1;
        cin >> n;
        cin.ignore();
        if (cin.eof()) { break; }

        vector<int> targets(n);
        for (int i = 0; i < n; i++) {
            cin >> targets[i];
            cin.ignore();
        }
        cin >> m;
        cin.ignore();
        vector<int> queries(m);
        for (int i = 0; i < m; i++) {
            cin >> queries[i];
            cin.ignore();
        }

        vector<int> sumVector;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                sumVector.push_back(targets[i] + targets[j]);
            }
        }

        std::sort(sumVector.begin(), sumVector.end());
        vector<int> absolutes(m);
        vector<int> bestSums(m);

        for (int j = 0; j < m; j++) {
            absolutes[j] = abs(sumVector[0] - queries[j]);
            bestSums[j] = sumVector[0];
        }
        for (int i = 0; i < n * n - n; i++) {
            for (int j = 0; j < m; j++) {
                if (absolutes[j] > sumVector[i] - queries[j]) {
                    absolutes[j] = abs(sumVector[i] - queries[j]);
                    bestSums[j] = sumVector[i];
                }
            }
        }

        cout << "Case " << caseCount << ":" << endl;
        for (int i = 0; i < m; i++) {
            cout << "Closest sum to " << queries[i] << " is " << bestSums[i] << "." << endl;
        }
    }
}