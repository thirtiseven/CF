#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int vis[123];
	std::fill(vis, vis+123, 0);
	int x, t;
	std::cin >> x;
	for (int i = 0; i < x; i++) {
		std::cin >> t;
		vis[t] = 1;
	}
	std::cin >> x;
	for (int i = 0; i < x; i++) {
		std::cin >> t;
		vis[t] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			std::cout << "Oh, my keyboard!\n";
			exit(0);
		}
	}
	std::cout << "I become the guy.\n";
}