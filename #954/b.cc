#include <iostream>
#include <algorithm>
#include <string>

const int maxn = 103;

int t, n, m;
int a[maxn][maxn];

int main(int argc, char *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cin >> t;
    while(t--) {
        std::cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                std::cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool yes = true;
                int temp = 0;
                if (i < n - 1 && a[i][j] > a[i + 1][j]) {
                    temp = a[i + 1][j];
                } else if (i < n - 1) {
                    yes = false;
                }
                if (j < m - 1 && a[i][j] > a[i][j + 1]) {
                    temp = std::max(temp, a[i][j + 1]);
                } else if (j < m - 1) {
                    yes = false;
                }
                if (i > 0 && a[i][j] > a[i - 1][j]) {
                    temp = std::max(temp, a[i - 1][j]);
                } else if (i > 0) {
                    yes = false;
                }

                if (j > 0 && a[i][j] > a[i][j - 1]) {
                    temp = std::max(temp, a[i][j - 1]);
                } else if (j > 0) {
                    yes = false;
                }
                if (yes) {
                    if (temp == 0) {
                        temp = a[i][j];
                    }
                    a[i][j] = temp;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                std::cout << a[i][j] << ' ';
            }
            std::cout << '\n';
        }
    }

}