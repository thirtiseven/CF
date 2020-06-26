#include <iostream>
#include <string>

int t, n;
std::string c, a, b;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		std::cin >> n >> c;
		a = c;
		b = c;
		int up = 0;
		for (int i = 0; i < n; i++) {
			if (c[i] == '2') {
				if (!up) {
					a[i] = b[i] = '1';
				} else {
					a[i] = '0';
					b[i] = '2';
				}
			} else if (c[i] == '1') {
				if (!up) {
					a[i] = '1';
					b[i] = '0';
					up = 1;
				} else {
					a[i] = '0';
					b[i] = '1';
				}
			} else {
				a[i] = b[i] = '0';
			}
		}
		std::cout << a << '\n' << b << '\n';
	}
}