#include <iostream>
#include <string>

int T;
std::string s[61];
int r, c;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> r >> c;
		for (int i = 0; i < r; i++) {
			std::cin >> s[i];
		}
		bool yes = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (s[i][j] == 'P') {
					yes = 0;
					break;
				}
			}
		}
		if (yes) {
			std::cout << "0\n";
			continue;
		}
		yes = 1;
		for (int i = 0; i < r; i++) {
			if (s[i][0] == 'P') {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "1\n";
			continue;
		}
		yes = 1;
		for (int i = 0; i < c; i++) {
			if (s[0][i] == 'P') {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "1\n";
			continue;
		}
		yes = 1;
		for (int i = 0; i < r; i++) {
			if (s[i][c-1] == 'P') {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "1\n";
			continue;
		}
		yes = 1;
		for (int i = 0; i < c; i++) {
			if (s[r-1][i] == 'P') {
				yes = 0;
				break;
			}
		}
		if (yes) {
			std::cout << "1\n";
			continue;
		}
		if (s[0][0] == 'A' || s[0][c-1] == 'A' || s[r-1][0] == 'A' || s[r-1][c-1] == 'A') {
			std::cout << "2\n";
			continue;
		}
		for (int i = 0; i < r; i++) {
			yes = 1;
			for (int j = 0; j < c; j++) {
				if (s[i][j] == 'P') {
					yes = 0;
					break;
				}
			}
			if (yes) {
				break;
			}
		}
		if (yes) {
			std::cout << "2\n";
			continue;
		}
		for (int i = 0; i < c; i++) {
			yes = 1;
			for (int j = 0; j < r; j++) {
				if (s[j][i] == 'P') {
					yes = 0;
					break;
				}
			}
			if (yes) {
				break;
			}
		}
		if (yes) {
			std::cout << "2\n";
			continue;
		}
		yes = 0;
		//////////
		for (int i = 0; i < r; i++) {
			if (s[i][0] == 'A') {
				yes = 1;
				break;
			}
		}
		for (int i = 0; i < c; i++) {
			if (s[0][i] == 'A') {
				yes = 1;
				break;
			}
		}
		for (int i = 0; i < r; i++) {
			if (s[i][c-1] == 'A') {
				yes = 1;
				break;
			}
		}
		for (int i = 0; i < c; i++) {
			if (s[r-1][i] == 'A') {
				yes = 1;
				break;
			}
		}
		/////////
		if (yes) {
			std::cout << "3\n";
			continue;
		}
		yes = 1;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (s[i][j] == 'A') {
					yes = 0;
					break;
				}
			}
		}
		if (yes) {
			std::cout << "MORTAL\n";
			continue;
		} else {
			std::cout << "4\n";
		}
	}
}