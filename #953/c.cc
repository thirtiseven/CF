#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>

using ll = long long;
const int maxn = 2e5+7;

ll n, k;

ll ans[maxn], vis[maxn];

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int t;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        ll kk = k;
        if (k % 2 == 1) {
            std::cout << "No\n";
            continue;
        }

        ll maxx = 0;
        for (int i = 1; i <= n; i++) {
            maxx += std::abs(n - i - i);
        }
        if (k > maxx) {
            std::cout << "No\n";
            continue;
        }

        for (int i = 1; i <= n; i++) {
            ans[i] = i;
            vis[i] = 0;
        }
        k /= 2;
        ll cur = n-1;
        ll pos = 1;
        while (k) {
            // std::cerr << "k = " << k << " cur = " << cur << " pos = " << pos << std::endl;
            if (k >= cur) {
                k -= cur;
                while (vis[pos] || vis[pos+cur]) {
                    if (pos + cur > n) {
                        cur -= 1;
                        goto end;
                    }
                    pos++;
                }
                vis[pos] = 1;
                vis[pos+cur] = 1;
                std::swap(ans[pos], ans[pos+cur]);
                // std::cout << "swap " << pos << " " << pos+cur << std::endl;
                cur -= 2;
            } else {
                cur -= 1;
            }
            end:;
        }
        std::cout << "Yes\n";
        ll check = 0;
        for (int i = 1; i <= n; i++) {
            std::cout << ans[i] << " ";
            check += std::abs(i - ans[i]);
        }
        assert(check == kk);
        // std::cerr << "check = " << check << std::endl;
        std::cout << '\n';

    }
    return 0;
}