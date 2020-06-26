#include <iostream>

int T;
int x, y, a, b;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> x >> y >> a >> b;
		if ((y-x)%(a+b)==0) {
			std::cout << (y-x)/(a+b) << '\n';
		} else {
			std::cout << "-1\n";
		}
	}
}