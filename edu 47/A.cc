#include <iostream>

const int maxn = 1234;
int n, m, c[maxn], a[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> c[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
	}
	int ans = 0, cur = 0;
	for (int i = 0; i < n && cur < m; i++) {
		if (a[cur] >= c[i]) {
			cur++;
			ans++;
		}
	}
	std::cout << ans;
}