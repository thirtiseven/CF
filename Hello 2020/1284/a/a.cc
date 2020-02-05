#include <iostream>
#include <string>
#include <vector>

int n, m;
std::vector<std::string> a, b;
std::string t;
int q, x;

int main(int argc, char *argv[]) {  
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> t;
		a.push_back(t);
	}
	for (int i = 0; i < m; i++) {
		std::cin >> t;
		b.push_back(t);
	}
	std::cin >> q;
	while (q--) {
		std::cin >> x;
		std::cout << a[(x-1)%n] << b[(x-1)%m] << '\n';
	}
}