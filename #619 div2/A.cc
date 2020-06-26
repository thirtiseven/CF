#include <iostream>
#include <string>

std::string a, b, c;
int T;
bool yes;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b >> c;
		yes = 1;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != c[i] && b[i] != c[i]) {
//				std::cout << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "YES\n";
		} else {
			std::cout << "NO\n";
		}
	}
}