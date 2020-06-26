#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 1e5+7;

int t, n, a[maxn], b[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 0; i < n; i++) {
			std::cin >> a[i];
		}
		std::sort(a, a+n);
		int l = 0, r = n-1;
		for (int i = 0; i < n; i++) {
			if (i%2==0) {
				b[i] = a[l];
				l++;
			} else {
				b[i] = a[r];
				r--;
			}
		}
		std::reverse(b, b+n);
		for (int i = 0; i < n; i++) {
			std::cout << b[i] << " \n"[i==n-1];
		}
	}
}