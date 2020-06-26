#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string s;
std::vector<int> x, y, z;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			x.push_back(i+1);
		} else {
			y.push_back(i+1);
		}
	}
	if (x.size() == 0 || y.size() == 0) {
		std::cout << "0\n";
		exit(0);
 	}
	int l = 0, r = y.size()-1;
	while (x[l] < y[r]) {
		z.push_back(x[l]);
		z.push_back(y[r]);
		l++, r--;
		if (l >= x.size() || r<0) {
			break;
		}
	}
	if (z.size() == 0) {
		std::cout << "0\n";
		exit(0);
	}
	std::sort(z.begin(), z.end());
	std::cout << 1 << '\n' << z.size() << '\n';
	for (int i = 0; i < z.size(); i++) {
		std::cout << z[i] << ' ';
	}
	std::cout << '\n';
}