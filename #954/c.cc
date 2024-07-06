#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 1e5 + 7;

int t, n, m, ind[maxn];

std::string s, c;

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> m >> s;
        for (int i = 0; i < m; i++) {
            std::cin >> ind[i];
        }
        std::cin >> c;
        // sort c
        std::sort(c.begin(), c.end());
        // sort and unique ind
        std::sort(ind, ind + m);
        m = std::unique(ind, ind + m) - ind;
        // set the new string
        for (int i = 0; i < m; i++) {
            s[ind[i] - 1] = c[i];
        }
        std::cout << s << '\n';
    }
}