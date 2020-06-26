#include <iostream>

int t, n, a, b, c, d;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> a >> b >> c >> d;
		if (n*(a+b) < (c-d) || n*(a-b) > (c+d)) {
			std::cout << "No\n";
		} else {
			std::cout << "Yes\n";
		}
	}
}