#include <iostream>
#include <algorithm>

int t, a, b;

int main(int argc, char *argv[]) {  
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b;
		if ((a+b)%3==0 && (std::max(a, b) <= std::min(a, b)*2)) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}