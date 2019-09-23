#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, a[123];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 1;
	std::sort(a, a+n);
	for (int i = 1; i < n; i++) {
		bool yes = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] % a[j] == 0) {
				yes = 0;
				break;
			}
		}
		if (yes) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}