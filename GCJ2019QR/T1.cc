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
		a = "";
		b = "";
		std::cin >> n;
		int pos = 0;
		if (n[0] == '1') {
			a += std::to_string(std::stoi(n.substr(0, 2))/2);
			b += std::to_string(std::stoi(n.substr(0, 2)) - std::stoi(n.substr(0, 2))/2);
			pos = 2;
		}
		for (int i = pos; i < n.length(); i++) {
			if (n[i] == '5') {
				a += "3";
				b += "2";
			} else if (n[i] != '0') {
				a += n[i]-1;
				b += "1";
			} else {
				a += "0";
				b += "0";
			}
		}
		std::cout << "Case #" << cas << ": " << a << ' ' << b << '\n';
		cas++;
	}
}