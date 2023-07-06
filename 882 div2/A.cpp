#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

const int maxn = 100;

int T;
int n, k, a[maxn];

int main(int argc, char *argv[]) {
    std::cin >> T;
    while (T--) {
        std::cin >> n >> k;
        std::vector<int> b;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            if (i > 0) {
                b.push_back(std::abs(a[i] - a[i - 1]));
            }
        }
        std::sort(b.begin(), b.end());
        int ans = 0;
        for (int i = 0; i < n - k; i++) {
            ans += b[i];
        }
        std::cout << ans << '\n';
    }
}