#include <iostream>
#include <algorithm>
#include <string>
#include <map>

const int maxn = 1e5+7;

int T, n, a[maxn];

int main(int argc, char *argv[]) {
    std::cin >> T;
    while (T--) {
        std::map<int, int> mp;
        std::cin >> n;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            mp[a[i]]++;
        }
        if (mp.size() == 1) {
            std::cout << "YES" << std::endl;
            continue;
        }
        if (mp.size() == 2) {
            auto it = mp.begin();
            if (std::abs(it->second - (++it)->second) <= 1) {
                std::cout << "YES" << std::endl;
                continue;
            }
        }
        std::cout << "NO" << std::endl;
    }
}