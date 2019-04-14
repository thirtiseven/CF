#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int T;
	std::cin >> T;
	std::string a, b;
	std::string n;
	int cas = 1;
	while (cas <= T) {
		std::cin >> n;
		for (auto i: n) {
			if (i == '4') {
				a += "1";
				b += "3";
			} else {
				a += i;
				b += "0";
			}
		}
		if (b[0] == '0') {
			b.erase(0);
		}
		std::cout << "Case #" << cas << ": " << a << ' ' << b << '\n';
		cas++;
	}
}