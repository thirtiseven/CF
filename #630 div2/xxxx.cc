#include <iostream>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int x, y;
	while (std::cin >> x >> y) {
		std::cout << (x&y) << '\n';
	}
}