#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	std::cin >> n >> s;
	int maxn = 0;
	for (int i = 1; i < s.length(); i++) {
		if (s.substr(0, i) == s.substr(i, i)) {
			maxn = i;
		}
	}
	std::cout << std::min(n-maxn+1, n);
}