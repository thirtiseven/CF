#include <iostream>
#include <string>

std::string a, b;

int main(int argc, char *argv[]) {  
	int aa, bb;
	std::cin >> aa >> bb;
	std::cin >> a >> b;
	int lab = 0;
	bool yes = 1;
	for (int i = 0; i < b.length();) {
		if (a[lab] == '*') {
			lab++;
			if (lab == a.length()) {
				break;
			}
			while (i < b.length() && b[i] != a[lab]) {
				i++;
			}
		}
		if (a[lab] != b[i]) {
			yes = 0;
			break;
		}
		lab++;
		i++;
	}
	if (lab != aa) {
		yes = 0;
	}
	std::cout << (yes?"YES":"NO");
}