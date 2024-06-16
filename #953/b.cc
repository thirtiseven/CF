#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;

int t;
ll n, a, b;

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> a >> b;
        ll ans = 0;
        if (b <= a) {
            ans = n * a;
        } else {
            ll k = std::min(b - a + 1, n);
            // sum_{i=1}^{k} b - i + 1 == (b + a) * k / 2
            ans += (b + b - k + 1) * k / 2;
            ans += (n - k) * a;
        }
        std::cout << ans << '\n';
    }
}