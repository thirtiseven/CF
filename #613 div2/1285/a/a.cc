#include <iostream>
#include <string>

int n;
std::string s;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> s;
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'L') {
			l++;
		} else {
			r++;
		}
	}
	std::cout << l+r+1 << '\n';
}