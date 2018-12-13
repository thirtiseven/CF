#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;

int a[maxn], n, k;

int main(int argc, char *argv[]) {  
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	for (int i = n-1; i > 0; i--) {
		a[i] = a[i] - a[i-1];
	}
	int cnt = 0;
	for (int i = 0; cnt < k; i++) {
		if (i < n && a[i] == 0) {
			continue;
		}
		std::cout << a[i] << '\n';
		cnt++;
	}
}