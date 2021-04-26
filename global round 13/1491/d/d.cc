#include <iostream>
#include <algorithm>
#include <vector>

using ll = long long;

ll q, u, v;
std::vector<int> a, b;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> q;
	while (q--) {
		a.clear();
		b.clear();
		std::cin >> u >> v;
		if (u > v) {
			std::cout << "NO\n";
			continue;
		}
		if (u == v) {
			std::cout << "YES\n";
			continue;
		}
		for (int i = 0; i < 32; i++) {
			if (u&(1<<i)) {
				a.emplace_back(i);
			}
			if (v&(1<<i)) {
				b.emplace_back(i);
			}
		}
		if (a.size() < b.size()) {
			std::cout << "NO\n";
			continue;
		} else {
			bool yes = 1;
			for (int i = 0; i < b.size(); i++) {
				if (a[i] > b[i]) {
					yes = 0;
					break;
				}
			}
			if (yes) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
		}
	}
}