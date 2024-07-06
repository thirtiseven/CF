#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using ll = long long;
const int maxn = 1e5+7;

int t;
ll n, k, a[maxn];
std::map<ll, std::vector<ll>> mp;
ll dp[maxn][2];

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while (t--) {
        mp.clear();
        std::cin >> n >> k;
        for (int i = 0; i < n; i++) {
            std::cin >> a[i];
            mp[a[i] % k].push_back(a[i]);
        }
        int odd = 0;
        for (auto it: mp) {
            if (it.second.size() % 2 == 1) {
                odd++;
            }
        }
        std::cerr << "odd: " << odd << "\n";
        if (odd > 1) {
            std::cout << "-1\n";
        } else {
            ll ans = 0;
            for (auto it: mp) {
                // std::cerr << "it.first: " << it.first << "\n";
                // std::cerr << "it.second: ";
                // for (auto i: it.second) {
                //     std::cerr << i << " ";
                // }
                // std::cerr << "\n";
                std::sort(it.second.begin(), it.second.end());
                if (it.second.size() % 2 == 0) {
                    for (int i = 0; i < it.second.size(); i+=2) {
                        if (i+1 >= it.second.size()) {
                            break;
                        }
                        ans += (it.second[i+1] - it.second[i]) / k;
                        // std::cerr << "ans: " << ans << "\n";
                    }
                } else {
                    dp[0][0] = 0;
                    dp[0][1] = 1e9+1;
                    if (it.second.size() > 1) {
                        dp[1][0] = (it.second[1] - it.second[0]) / k;
                        dp[1][1] = 1e9+1;
                    }
                    for (int i = 2; i < it.second.size(); i++) {
                        if (i % 2 == 0) {
                            dp[i][0] = dp[i-1][0];
                            dp[i][1] = (it.second[i] - it.second[i-1]) / k + std::min(dp[i-2][0], dp[i-1][1]);
                        } else {
                            dp[i][0] = dp[i-2][0] + (it.second[i] - it.second[i-1]) / k;
                            dp[i][1] = dp[i-1][1];
                        }
                        // std::cerr << "dp[" << i << "][0]: " << dp[i][0] << "\n";
                        // std::cerr << "dp[" << i << "][1]: " << dp[i][1] << "\n";
                    }
                    int nn = it.second.size();
                    ans += std::min(dp[nn-1][0], dp[nn-1][1]);
                    // std::cerr << "ans: " << ans << "\n";
                }
            }
            std::cout << ans << '\n';
        }
    }
}