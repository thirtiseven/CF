#include <iostream>

const int maxn = 123;

int main(int argc, char *argv[]) {  
	int n;
	int a[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i < n-1; i++) {
		if (a[i] == 0 && a[i-1] == 1 && a[i+1] == 1) {
			a[i] = 2;
		}
	}
	for (int i = 1; i < n-1; i++) {
		if (a[i] == 1 && a[i-1] == 2 && a[i+1] == 2) {
			a[i] = 0;
			a[i-1] = 0;
			a[i+1] = 0;
			ans++;
		}
	}
	for (int i = 1; i < n-1; i++) {
		if ((a[i] == 0||a[i] == 2) && a[i-1] == 1 && a[i+1] == 1) {
			a[i+1] = 0;
			ans++;
		}
	}
	std::cout << ans << '\n';
}