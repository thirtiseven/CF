#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n;
	char s[123];
	std::cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		if (n%i==0) {
			std::reverse(s, s+i);
		}
	}
	std::cout << s;
}