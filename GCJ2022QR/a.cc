#include <iostream>
#include <algorithm>
#include <string>

int t, r, c;

int main(int argc, char *argv[]) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	for (int CAS = 1; CAS <= t; CAS++) {
		std::cin >> r >> c;
		std::cout << "Case #" << CAS << ":\n";
		int cc = c*2+1;
		int rr = r*2+1;
		for (int i = 0; i < rr; i++) {
			for (int j = 0; j < cc; j++) {
				if (i < 2 && j < 2) {
					std::cout << ".";
				} else if (i % 2 == 0) {
					if (j % 2 == 0) {
						std::cout << "+";
					} else {
						std::cout << "-";
					}
				} else {
					if (j % 2 == 0) {
						std::cout << "|";
					} else {
						std::cout << ".";
					}
				}
			}
			std::cout << '\n';
		}
	}
}