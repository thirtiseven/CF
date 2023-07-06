#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 2e5+7;

int T, n, a[maxn];

int main(int argc, char *argv[]) {
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        int ans = 0;
        int cur = -1;
        for (int i = 0; i < n; i++) {
            if (cur == -1) {
                cur = a[i];
                ans ++;
            } else {
                cur &= a[i];
            }
            if (cur == 0) {
                cur = -1;
            }
        }
        if (cur > 0 && ans > 1) {
            ans -= 1;
        }
        std::cout << ans << '\n';
    }
    
}