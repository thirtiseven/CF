#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	int p[123], a[123];
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> p[i];
		a[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		std::cout << a[i] << " ";
	}
}