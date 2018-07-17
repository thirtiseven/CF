#include <iostream>
#include <string>
#include <algorithm>

long long n, x, y;
std::string a;

int main(int argc, char *argv[]) {  
	std::cin >> n >> x >> y >> a;
	std::string s;
	s += a[0];
	char now = a[0];
	for (int i = 1; i < a.length(); i++) {
		if (a[i] != now) {
			s += a[i];
			now = a[i];
		}
	}
	if (s=="1") {
		std::cout << "0";
	} else {
		long long zeros = s.length()/2 + (s[0] == '0'&&s.length()%2==1);
		std::cout << (zeros-1)*std::min(x, y)+y;
	}
}