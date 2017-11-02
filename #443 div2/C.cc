#include <iostream>

#define maxn 500010

int main(int argc, char *argv[]) {  
	int n, t[maxn];
	char s[maxn];
	std::cin >> n;
	int a = 0, b = 1, c;
	bool isc = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> s[i] >> t[i];
		if(s[i] == '|') {
			a |= t[i];
		} else if(s[i] == '&') {
			b &= t[i];
		} else {
			if(!isc) {
				c = t[i];
				isc = 1;
			} else {
				c ^= t[i];
			}
		}
	}
	std::cout << 3 << "\n| " << a << "\n& " << b << "\n^ " << c << "\n";
	return 0;
}