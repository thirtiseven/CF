#include <iostream>
#include <algorithm>
#include <string>

int t, a, b, n;

int main(int argc, char *argv[]) {
    std::cin >> t;
    while (t--) {
        std::cin >> n >> a >> b;
        int ans = 0;
        if (n % 2 == 1) ans += a;
        ans += std::min(n / 2 * b, n / 2 * 2 * a);
        std::cout << ans << '\n';
    } 
}