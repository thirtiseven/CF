#include <iostream>
#include <algorithm>
#include <string>

int t, a, b, c;

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> c;
        int ans = 1000;
        for (int i = 0; i < 11; i++) {
            ans = std::min(ans, std::abs(a - i) + std::abs(b - i) + std::abs(c - i));
        }
        std::cout << ans << '\n';
    }
}