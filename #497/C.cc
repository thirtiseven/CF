#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int main(int argc, char *argv[]) {  
	int n, a[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}	
	std::sort(a, a+n);
	int ans = 0;
	int add = 1;
	for (int i = 0; i < n; i++) {
		while (i+add < n && a[i] == a[i+add]) add++;
		if (i+add >= n) break;
		if (a[i] < a[i+add]) {
			ans++;
		}
	}
	std::cout << ans;
}