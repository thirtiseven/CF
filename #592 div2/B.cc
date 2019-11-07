#include <iostream>
#include <string>
#include <algorithm>

const int maxn = 1003;

std::string s;
int n, T;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> n >> s;
		int add = 0;
		for (auto it: s) {
			if (it == '1') {
				add++;
			}
		}
		int x = 10000;
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				x = i;
				break;
			}
		}
		for (int i = n-1; i >= 0; i--) {
			if (s[i] == '1') {
				x = std::min(x, n-1-i);
				break;
			}
		}
		std::cout << std::max(n+add, 2*n-2*x) << '\n';
	}
}