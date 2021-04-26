#include <iostream>
#include <algorithm>
#include <string>

int T, n;
std::string a, b;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	while (T--) {
		std::cin >> n >> a >> b;
		int red = 0, blue = 0, equal = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i]) {
				red++;
			} else if (a[i] < b[i]) {
				blue++;
			} else {
				equal++;
			}
		}
		if (red > blue) {
			std::cout << "RED\n";
		} else if (red == blue) {
			std::cout << "EQUAL\n";
 		} else {
			std::cout << "BLUE\n";
		}
	}
}