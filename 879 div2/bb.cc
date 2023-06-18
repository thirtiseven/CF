#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 123;
const int inf = 0x3f3f3f3f;

int T;
std::string L, R;

int dp[maxn][4][4];
// dp[i][l][r]
// l: 0: 0, 1: 9, 2: L[i], 3: L[i] + 1
// r: 0: 0, 1: 9, 2: R[i], 3: R[i] - 1

int main(int argc, char *argv[]) {
    std::cin >> T;
    while (T--) {
        std::cin >> L >> R;
        int n = R.size();
        if (L.size() < R.size()) {
            L = std::string(R.size() - L.size(), '0') + L;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (L[i] != R[i]) {
                ans += R[i] - L[i];
                ans += 9 * (n - i - 1);
                break;
            }
        }
        std::cout << ans << '\n';
    }
}