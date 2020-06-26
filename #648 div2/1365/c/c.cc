#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int n, a[maxn], b[maxn], pos[maxn], num[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::fill(pos, pos+maxn, 0);
	std::fill(num, num+maxn, 0);
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
		pos[b[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		num[(i+n-pos[a[i]])%n]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = std::max(ans, num[i]);
	}
	std::cout << ans << '\n';
}