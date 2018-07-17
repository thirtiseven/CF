#include <iostream>

int main(int argc, char *argv[]) {  
	int n, k, a[1234];
	bool flag = 0;
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] > k) {
			flag = 1;
		}
	}
	if (flag) {
		int cnt = 0;
		for (int i = 0; a[i] <= k; i++) {
			cnt++;
		}
		for (int i = n-1; a[i] <= k; i--) {
			cnt++;
		}
		std::cout << cnt;
	} else {
		std::cout << n;
	}
}