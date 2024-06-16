#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;

const int maxn = 1e3 + 5;

int t, n, a[maxn];

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        std::sort(a, a + n - 1);
        ll ans = a[n - 1] + a[n - 2];
        std::cout << ans << '\n';
    }
}