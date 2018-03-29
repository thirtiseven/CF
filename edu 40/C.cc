#include <iostream>
#include <algorithm>
#include <cmath>

const int maxn = 400009;

int main(int argc, char *argv[]) {  
	long long n;
	long long a[maxn];
	long long step = 1;
	std::cin >> n;
	std::cin >> a[0];
	for (int i = 1; i < n; i++) {
		std::cin >> a[i];
		if (std::abs(a[i] - a[i-1]) != 1) {
			step = abs(a[i] - a[i-1]);
//			std::cout << step;
		}
	}
	if (step == 0) {
			std::cout << "NO";
			return 0;
	}
	long long x = step;
	if (x == 1) {
		std::cout << "YES\n" << 1000000000 << " " << x;
		return 0;
	}
	bool yes = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i-1] == 1 && (a[i]-1)%x == 0) {
//			std::cout << a[i] << " " << a[i-1];
//			std::cout << "!!!\n";
			yes = 0;
		} else if (a[i] - a[i-1] == -1 && (a[i-1]-1)%x == 0) {
//			std::cout << a[i] << " " << a[i-1];
//			std::cout << "!!!!\n";
			yes = 0;
		} else if (std::abs(a[i] - a[i-1]) != 1 && std::abs(a[i] - a[i-1]) != x) {
//			std::cout << a[i] << " " << a[i-1];
//			std::cout << "!!!!!\n";
			yes = 0;
		}
	}
	if (yes) {
		std::cout << "YES\n" << 1000000000 << " " << x;
	} else {
		std::cout << "NO\n";
	}
}