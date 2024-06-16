#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;

const int maxn = 2e5 + 5;

int t, n;
ll a[maxn], c;
int ans[maxn];

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> c;
        ll maxx = 0;
        int max_id = 0;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (a[i] > maxx) {
                maxx = a[i];
                max_id = i;
            }
        }
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            if (i == max_id && (a[i] > a[0] + c || i == 0)) {
                ans[i] = 0;
            } else if (cur + c + a[i] < maxx) {
                ans[i] = i + 1;
            } else {
                ans[i] = i;
            }
            cur += a[i];
        }
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << ' ';
        }
        std::cout << '\n';
    }
}