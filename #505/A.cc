#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	if (n==1) {
		std::cout << "Yes\n";
		exit(0);
	}
	int	vis[33];
	std::fill(vis, vis+33, 0);
	for (int i = 0; i < n; i++) {
		vis[int(s[i]-'a')]++;
	}
	for (int i = 0; i < 27; i++) {
		if (vis[i] > 1) {
			std::cout << "Yes\n";
			exit(0);
		}
	}
	std::cout << "No\n";
}