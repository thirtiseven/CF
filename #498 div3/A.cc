#include <iostream>

int main(int argc, char *argv[]) {  
	int n, a[1234];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (a[i] > 0 && a[i] % 2 == 0) {
			a[i]--;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << a[i] << ' ';
	}
}