#include <iostream>
#include <algorithm>

const int maxn = 2e5+9;

int main(int argc, char *argv[]) {  
	unsigned long long n, m, a[maxn], b[maxn], aa[maxn];
	std::cin >> n >> m;
	aa[0] = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		aa[i] = aa[i-1] + a[i];
	}
	for (int i = 1; i <= m; i++) {
		std::cin >> b[i];
	}
	for (int i = 1; i <= m; i++) {
		int cnt = std::lower_bound(aa+1, aa+n+1, b[i]) - aa - 1;
		std::cout << cnt+1 << " " << b[i]-aa[cnt] << '\n';
	}
	
}