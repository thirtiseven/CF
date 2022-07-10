#include <iostream>
#include <algorithm>
#include <string>


int t, n;
std::string a, b;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n;
		std::cin >> a >> b;
		bool yes = 1;
		for (int i = 0; i < n; i++) {
			if (a[i] == b[i] && a[i] == '1') {
				yes = 0;
			}
		}
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}