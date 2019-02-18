#include <iostream>
#include <string>

using ll = long long;

int main(int argc, char *argv[]) {  
	int n;
	std::string s;
	ll a, h = 0, ha = 0, har = 0, hard = 0;
	std::cin >> n >> s;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		if (s[i] == 'h') {
			h += a;
		} else if (s[i] == 'a') {
			ha = std::min(h, ha+a);
		} else if (s[i] == 'r') {
			har = std::min(ha, har+a);
		} else if (s[i] == 'd') {
			hard = std::min(har, hard+a);
		}
	}
	std::cout << hard << '\n';
}