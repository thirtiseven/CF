#include <iostream>
#include <algorithm>

const int maxn = 3e5+7;

int t, n, a[maxn], pos[maxn];

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		for (int i = 1; i <= n; i++) {
			std::cin >> a[i];
			pos[a[i]] = i;
		}
		if (a[1] > a[n]) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n";
		}
	}
}