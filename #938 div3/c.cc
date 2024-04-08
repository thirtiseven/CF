#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 2e5+6;
using ll = long long;

int t, n, k;
ll a[maxn], pre[maxn], suf[maxn];

int main(int argc, char *argv[]) {
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            std::cin >> a[i];
            sum += a[i];
        }
        pre[0] = suf[n+1] = 0;
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i-1] + a[i];
            if (pre[i] > (k + 1) / 2) {
                x = i - 1;
                break;
            }
        }
        for (int i = n; i >= 1; i--) {
            suf[i] = suf[i+1] + a[i];
            if (suf[i] > k / 2) {
                y = n - i;
                break;
            }
        }
        // for (int i = 1; i <= n; i++) {
        //     std::cout << pre[i] << ' ';
        // }
        // std::cout << '\n';
        // for (int i = 1; i <= n; i++) {
        //     std::cout << suf[i] << ' ';
        // }
        // std::cout << '\n';
        // std::cout << x << ' ' << y << '\n';
        if (sum <= k) {
            std::cout << n << "\n";
        } else {
            std::cout << x + y << '\n';
        }
    }
}