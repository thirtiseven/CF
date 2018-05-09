#include <iostream>
#include <algorithm>

const int maxn = 2e5+8;

int main(int argc, char *argv[]) {  
	int n, k, a[maxn];
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a+n);
	if (k == 0 && a[0]>1) {
		std::cout << a[0]-1;
	} else if (k == 0 && a[0]==1) {
		std::cout << -1;
	}else if (a[k-1] == a[k] || a[k-1] < 1 || a[k-1] > 1e9) {
		std::cout << -1;
	} else
	std::cout << a[k-1];
}