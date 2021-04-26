#include <iostream>
#include <algorithm>

int t, a, b;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> a >> b;
		std::cout << a*b << '\n';
	}
}