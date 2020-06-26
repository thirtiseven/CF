#include <iostream>
#include <algorithm>
#include <string>

std::string s;
int T;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> s;
		int zero = 0, one = 0;
		for (auto it: s) {
			if (it == '0') zero++;
			else one++;
		}
		if (std::min(one, zero) % 2 == 0) {
			std::cout << "NET\n";
		} else {
			std::cout << "DA\n";
		}
	}
}