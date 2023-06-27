#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double r, h, s;
    while (cin >> r >> h >> s) {
        if (r == 0 && h == 0 && s == 0) {
            break;
        }
        double total = ((M_PI + asin(r / h) * 2) / (2 * M_PI)) * 2 * M_PI * r;

        total += sqrt(h * h - r * r) * 2;

        total += total * (s / 100);

        printf("%.2f\n", total);
    }
}