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
	long long ans;
	if (s == "0" || s.length() == 2 || s == "101") {
		ans = y;
	} else if (s == "1") {
		ans = 0;
	} else if (s == "010") {
		ans = std::min(2*y, x+y);
	} else {
		long long plana = 0, planb = 0;
		plana = ((s.length()-2)/2)*x+y;
		long long zeros = s.length()/2 + (s[0] == '0');
		planb = zeros*y;
		if (s[0] == '0' && s.length()%2==1) {
			plana += std::min(x, y);
		}
		ans = std::min(plana, planb);
	}
	std::cout << ans << '\n';
}