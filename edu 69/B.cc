#include <iostream>
#include <algorithm>

const int maxn = 2e5+7;
int a[maxn], n;

int main(int argc, char *argv[]) {  
	std::cin >> n;
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		if (a[i] == n) {
			pos = i;
		}
	}
	bool yes = 1;
	for (int i = 1; i < pos; i++) {
		if (a[i] > a[i+1]) {
			yes = 0;
		}
	}
	for (int i = pos; i < n; i++) {
		if (a[i] < a[i+1]) {
			yes = 0;
		}
	}
	std::cout << (yes?"YES\n":"NO\n");
}