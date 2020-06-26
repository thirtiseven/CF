#include <iostream>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int a, b, c, d, t;
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b >> c >> d;
		std::cout << a << ' ' << c << ' ' << c << '\n';
	}
}