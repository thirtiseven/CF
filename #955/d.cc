#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;
const int maxn = 503;

ll t, n, m, k;

std::string snowy[maxn];
ll a[maxn][maxn], pre[maxn][maxn];

ll sum(int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                std::cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            std::cin >> snowy[i];
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                pre[i][j] = 0;
            }
        }
        // calculate prefix sum of snowy
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (snowy[i][j-1] == '1');
            }
        }
        ll snowy_sum = 0, no_snowy_sum = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (snowy[i][j-1] == '1') {
                    snowy_sum += a[i][j];
                } else {
                    no_snowy_sum += a[i][j];
                }
            }
        }
        ll diff = snowy_sum - no_snowy_sum;
        std::cerr << "snowy_sum: " << snowy_sum << " no_snowy_sum: " << no_snowy_sum << " diff: " << diff << "\n";
        if (diff == 0) {
            std::cout << "YES\n";
            continue;
        }
        for (int i = 1; i <= n - k + 1; i++) {
            for (int j = 1; j <= m - k + 1; j++) {
                ll snowy_cnt = sum(i, j, i+k-1, j+k-1);
                ll no_snowy_cnt = k*k - snowy_cnt;
                std::cerr << "i: " << i << " j: " << j << " snowy_cnt: " << snowy_cnt << " no_snowy_cnt: " << no_snowy_cnt << "\n";
                if (snowy_cnt != no_snowy_cnt && diff % std::abs(snowy_cnt - no_snowy_cnt) == 0) {
                    std::cout << "YES\n";
                    goto done;
                }
            }
        }
        std::cout << "NO\n";
        done:;
    }
}