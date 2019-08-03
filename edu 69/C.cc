#include <iostream>
#include <vector>
#include <algorithm>

const int maxn = 3e5+7;
int n, k, a[maxn];

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> c;
	for (int i = 0; i < n-1; i++) {
		c.push_back(a[i+1]-a[i]);
	}
	std::sort(c.begin(), c.end());
	int ans = a[n-1]-a[0];
	for (int i = 0; i < k-1; i++) {
		ans -= c[n-2-i];
	}
	std::cout << ans << '\n';
}