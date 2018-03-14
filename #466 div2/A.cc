#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, d, a[123];
	std::cin >> n >> d;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int cnt = 0;
	int minn = 0;
	std::sort(a, a+n);
	for (int i = 0; i < n; i++) {
		while (i+cnt < n && a[i+cnt] - a[i] <= d) {
			cnt++;
		}
		minn = std::max(minn, cnt);
		cnt = 0;
	}
	std::cout << n-minn;
}