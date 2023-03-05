#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    double h[n];
    std::cin >> h[0];
    double l = 0, r = 1000000000.0;
    while (r > l + 0.000000001) {
        h[1] = (l + r) / 2;
        bool flag = true;
        for (int i = 2; i < n; i++) {
            h[i] = 2 * h[i-1] - h[i - 2] + 2;
            if (h[i] <= 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            r = h[1];
        } else {
            l = h[1];
        }
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << h[n - 1];
    return 0;
}