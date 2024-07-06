#include <iostream>
#include <algorithm>
#include <string>

using ll = long long;
const int maxn = 23;

ll t, n;
std::string s;
ll dp[maxn][2];

ll gao(int idx) {
    if (idx >= 2) {
        if (dp[idx-2][0] == 1) {
            return 0;
        }
        return dp[idx-2][0];
    }
    return 0;
}

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> s;

        if (n == 3 && s[1] == '0') {
            std::cout << std::min((s[0]-'0') + (s[2]-'0'), (s[0]-'0') * (s[2]-'0')) << '\n';
            continue;
        }

        if (n >= 3) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    std::cout << "0\n";
                    goto end;
                }
            }
        }

        dp[0][0] = s[0] - '0';
        dp[0][1] = 100000;

        for (int i = 1; i < n; i++) {
            if (s[i] == '1') {
                dp[i][0] = dp[i-1][0];
                dp[i][1] = std::min(gao(i) + (s[i-1]-'0') * 10 + 1, dp[i-1][1]);
            } else {
                dp[i][0] = dp[i-1][0] + (s[i]-'0');
                dp[i][1] = std::min(gao(i) + (s[i-1]-'0') * 10 + (s[i]-'0'), dp[i-1][1] + (s[i]-'0'));
            }
        }

        std::cout << dp[n-1][1] << '\n';
        end:;
    }
}