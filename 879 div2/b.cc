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
        for (int i = 0; i < R.size(); ++i) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    dp[i][j][k] = -inf;
                }
            }
        }
        dp[0][2][2] = R[0] - L[0];
        if (R[0] > L[0]) {
            dp[0][2][3] = R[0] - L[0] - 1;
            dp[0][3][2] = R[0] - L[0] - 1;
        }
        if (R[0] > L[0] + 1) {
            dp[0][3][3] = R[0] - L[0] - 2;
        }
        // dp[i][l][r]
        // l: 0: 0, 1: 9, 2: L[i], 3: L[i] + 1
        // r: 0: 0, 1: 9, 2: R[i], 3: R[i] - 1
        for (int i = 1; i < n; i++) {
            int freel = -inf;
            freel = std::max(freel, dp[i - 1][0][1]);
            freel = std::max(freel, dp[i - 1][0][2]);
            freel = std::max(freel, dp[i - 1][0][3]);
            freel = std::max(freel, dp[i - 1][1][0]);
            freel = std::max(freel, dp[i - 1][1][2]);
            freel = std::max(freel, dp[i - 1][1][3]);
            freel = std::max(freel, dp[i - 1][1][0]);
            freel = std::max(freel, dp[i - 1][1][0]);
            dp[i][0][1] = std::max(dp[i - 1][0][1], dp[i - 1][1][0]) + 9;
            dp[i][1][0] = dp[i][0][1];
            dp[i][0][1] = std::max(dp[i][0][1], dp[i - 1][0][3] + 9);
            dp[i][0][1] = std::max(dp[i][0][1], dp[i - 1][0][2] + R[i] - 1 - '0');
            dp[i][1][0] = std::max(dp[i][1][0], dp[i - 1][3][1] + 9);
            dp[i][1][0] = std::max(dp[i][1][0], dp[i - 1][2][1] + '9' - L[i] - 1);
            dp[i][0][2] = 
            dp[i][0][3]
            dp[i][1][2]
            dp[i][1][3]
            dp[i][2][0]
            dp[i][3][0]
            dp[i][2][1]
            dp[i][3][1]
            dp[i][2][2] = dp[i - 1][2][2] + R[i] - L[i];
            if (R[i] > L[i]) {
                dp[i][2][3] = R[i] - L[i] - 1 + dp[i-1][2][2];
                dp[i][3][2] = R[i] - L[i] - 1 + dp[i-1][2][2];
            }
            if (R[i] > L[i] + 1) {
                dp[i][3][3] = R[i] - L[i] - 2 + dp[i-1][2][2];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; ++j) {
                for (int k = 0; k < 4; ++k) {
                    if (dp[i][j][k] >= 0) {
                        std::cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';
                    }
                }
            }
            std::cout << "==========";
        }
        int ans = 0;
        for (int l = 0; l < 4; ++l) {
            for (int r = 0; r < 4; ++r) {
                ans = std::max(ans, dp[n - 1][l][r]);
            }
        }
        std::cout << ans << '\n';
    }
}