#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll u, v;
	while (std::cin >> u >> v) {
		std::cout << (u&v) << '\n';
	}
}