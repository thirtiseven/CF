#include <iostream>
#include <algorithm>

const int maxn = 1009;
#define inf 0x7f7f7f7f

int main(int argc, char *argv[]) {  
	int n, m, f[maxn];
	std::cin >> n >> m;
	for(int i = 0; i < m; i++) {
		std::cin >> f[i];
	}
	std::sort(f, f+m);
	int ans = inf;
	for(int i = 0; i <= m-n; i++) {
		ans = std::min(ans, f[i+n-1]-f[i]);
	}
	std::cout << ans << std::endl;
	return 0;
}