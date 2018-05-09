#include <iostream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {  
	int T;
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		int d;
		std::string p;
		std::cin >> d >> p;
		std::cout << "Case #" << CAS << ": ";
		int ans = 0, now = 1;
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'C') {
				now *= 2;
			} else {
				ans += now;
			}
		}
		if (ans <= d) {
			std::cout << "0\n";
			continue;
		}
		int tot = 0;
		for (int i = p.length(); i > 0; i--) {
			if (p[i-1] == 'C' && p[i] == 'S') {
				std::swap(p[i-1], p[i]);
				tot++;
				ans = 0, now = 1;
				for (int i = 0; i < p.length(); i++) {
					if (p[i] == 'C') {
						now *= 2;
					} else {
						ans += now;
					}
				}
			}
			if (ans <= d) {
				std::cout << tot << '\n';
				break;
			}
			if (i == 1) {
				std::cout << ""
			}
		}
	}
}