#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 123;

int T, n, a[maxn];

int main(int argc, char *argv[]) {
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        int pos = 0, neg = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            if (a[i] > 0) ++pos;
            else if (a[i] < 0) ++neg;
        }
        int ans = 0;
        if (neg > pos) {
            ans += (neg - pos + 1) / 2;
            neg -= ans;
            pos += ans;
        }
        if (neg % 2 == 1) {
            ans ++;
        }
        std::cout << ans << '\n';
    }
}