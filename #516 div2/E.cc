#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int ans = -1;
	std::string s[40];
	std::cout << "0 0" << std::endl;
	std::cin >> s[0];
	for (int i = 1; i < n; i++) {
		std::cout << i*2 << " " << 0 << std::endl;
		std::cin >> s[i];
		if (s[i] != s[i-1]) {
			ans = i;
		}
	}
	std::cout << ans*2-1 << " " << 1 << " " << ans*2-1 << " " << 2 << '\n';
}