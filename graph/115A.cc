#include <iostream>

const int maxn = 2345;

int main(int argc, char *argv[]) {  
	int fa[maxn], n;
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> fa[i];
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int cnt = 1;
		for (int j = i; fa[j] > 0; j = fa[j]) {
			cnt++;
		}
		ans = std::max(cnt, ans);
	}
	std::cout << ans << '\n';
	return 0;
}