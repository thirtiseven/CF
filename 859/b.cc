#include <iostream>

const int maxn = 103;

int t, n, a[maxn];

int main() {
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        int m = 0, b = 0;
        bool yes = 1;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (a[i] % 2 == 0) {
                m += a[i];
            } else {
                b += a[i];
            }
        }
        if (m <= b) {
            yes = 0;
        }
        std::cout << (yes?"YES\n":"NO\n");
    }
}