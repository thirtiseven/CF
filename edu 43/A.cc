#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::string s;
	int n;
	std::cin >> n >> s;
	if (s == "0") {
		std::cout << "0";
		return 0;
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '0') {
			ans++;
		}
	}
	std::cout << "1";
	for (int i = 0; i < ans; i++) {
		std::cout << "0";
	}
}