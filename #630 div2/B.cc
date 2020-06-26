#include <iostream>
#include <set>
#include <algorithm>

const int maxn = 1004;
int a[maxn], c[maxn], t, n;
int p[14] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		std::fill(c, c+n, 0);
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
			for (int j = 1; j <= 11; j++) {
				if (a[i]%p[j] == 0) {
					a[i] = c[i] = j;
					break;
				}
			}
		}
		//数组离散化 含重复元素
		std::sort(c, c+n);
		int size = std::unique(c, c+n) - c;//size为离散化后元素个数
		for (int i = 0; i < n; i++) {
			a[i] = std::lower_bound(c, c+size, a[i]) - c + 1;//k为b[i]经离散化后对应的值
		}
		std::cout << size << '\n';
		for (int i = 0; i < n; i++) {
			std::cout << a[i] << " \n"[i==n-1];
		}
	}
}