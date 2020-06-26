#include <iostream>
#include <string>

int t, n, a, b;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> a >> b;
		for (int i = 0; i < n; i++) {
			std::cout << char('a'+i%b);
		}
		std::cout << '\n';
	}
}