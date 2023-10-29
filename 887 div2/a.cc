#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

const int maxn = 503;

int t, n, a[maxn];

int main(int argc, char *argv[]) {
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int ans = INT_MAX;
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i - 1] < 0) {
                ans = 0;
            } else {
                ans = std::min(ans, (a[i] - a[i - 1] + 2) / 2);
            }
        }
        std::cout << ans << '\n';
    }
}