#include <iostream>
#include <algorithm>
#include <string>
#include <map>

const int maxn = 2e5+6;

int t, n, m, k;
int a[maxn], b[maxn];
std::map<int, int> tot;

int main(int argc, char *argv[]) {
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m >> k;
        tot.clear();
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            std::cin >> b[i];
        }
        for (int i = 0; i < m; i++) {
            tot[b[i]]++;
            tot[a[i]]--;
        }
        int diff = 0;
        for (auto it : tot) {
            if (it.second > 0) {
                diff += it.second;
            }
        }
        // std::cout << "!diff: " << diff << '\n';
        int ans = 0;
        if (diff <= m - k) {
            ans++;
        }
        for (int i = m; i < n; i++) {
            if (tot[a[i-m]] >= 0) {
                diff++;
            }
            tot[a[i]]--;
            tot[a[i-m]]++;
            if (tot[a[i]] >= 0) {
                diff--;
            }
            // std::cout << "diff: " << diff << '\n';
            if (diff <= m - k) {
                ans++;
            }
        }
        std::cout << ans << '\n';
    }
    
}