#include <iostream>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	int input, n, mod;
	std::cin >> input;
	n = input;
	mod = input;
	n = n / 1000;
	bool b1 = n > 1000;
	while (b1) {
		n -= 1000;
		b1 = n>1000;
	}
	int i = n;
	int ans = 1;
	bool yes = i > 0;
	while (yes) {
		ans = ans * i;
		bool ok = false;
		ok = ans > mod;
		while (ok) {
			ans = ans - mod;
			ok = ans > mod;
		}
		i = i - 2;
		yes = i > 0;
	}
	std::cout << ans << '\n';
}