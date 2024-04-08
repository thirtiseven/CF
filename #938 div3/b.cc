#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 250000+10;

int t, n, c, d;
int a[maxn], b[maxn];

int main(int argc, char *argv[]) {
    std::cin >> t;
    while (t--) {
        std::cin >> n >> c >> d;
        for (int i = 0; i < n * n; i++) {
            std::cin >> b[i];
        }
        a[0] = 0;
        for (int i = 1; i < n; i++) {
            a[i] = a[i-1] + d;
        }
        for (int i = 1; i < n; i++) {
            a[i*n] = a[(i-1)*n] + c;
            for (int j = 1; j < n; j++) {
                a[i*n+j] = a[i*n+j-1] + d;
            }
        }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         std::cout << a[i*n+j] << ' ';
        //     }
        //     std::cout << '\n';
        // }
        std::sort(a, a+n*n);
        std::sort(b, b+n*n);
        // for (int i = 0; i < n * n; i++) {
        //     std::cout << a[i] << ' ';
        // }
        // std::cout << '\n';
        // for (int i = 0; i < n * n; i++) {
        //     std::cout << b[i] << ' ';
        // }
        // std::cout << '\n';
        int diff = a[0] - b[0];
        bool ok = true;
        for (int i = 0; i < n * n; i++) {
            if (a[i] - b[i] != diff) {
                ok = false;
                break;
            }
        }
        if (ok) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }    
}