#include <iostream>
#include <algorithm>

int T, a[4];

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> a[0] >> a[1] >> a[2];
		std::sort(a, a+3);
		bool yes = 1;
		if (a[0] + a[1] < a[2]-1) {
			yes = 0;
		}
		if (yes) {
			std::cout << "Yes\n";
		} else {
			std::cout << "No\n";
		}
	}
}