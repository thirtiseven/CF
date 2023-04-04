#include <iostream>
#include <algorithm>

const int maxn = 1e5+7;

int a, b, c;
int t;

int main() {
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> a >> b >> c;
		if (a + b == c) {
			std::cout << "+\n";
		} else {
			std::cout << "-\n";
		}
	}	
  
}
