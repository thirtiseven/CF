#include <iostream>
#include <string>

int T;
std::string a, b;

int main(int argc, char *argv[]) {  
	std::cin >> T;
	while (T--) {
		std::cin >> a >> b;
		std::string x = a, y = a;
		for (int i = a.length()-2; i >= 0; i--) {
			x[i] = std::min(x[i], x[i+1]);
		}
		int label = -1;
		for (int i = 0; i < a.length(); i++) {
			if (x[i] < a[i]) {
				y[i] = x[i];
				label = i;
				break;
 			}
		}
		if (label != -1) {
			for (int i = a.length()-1; i >= 0; i--) {
				if (a[i] == x[label]) {
					y[i] = a[label];
					break;
				}
			}
		}
//		std::cout << a << ' ' << b << ' ' << x << ' ' << y << '\n';
		if (y < b) {
			std::cout << y << '\n';
		} else {
			std::cout << "---\n";
		}
	}
}