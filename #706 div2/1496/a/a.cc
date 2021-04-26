#include <iostream>
#include <algorithm>
#include <string>

int t, n, k;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> k >> s;
		bool yes = 1;
		for (int i = 0; i < k; i++) {
			if (i < n-1-i && s[i] == s[n-1-i]) {
				continue;
			} else {
				yes = 0;
			}
		}
		if (n == 2*k) {
			yes = 0;
		}
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
 		}	
	}
}