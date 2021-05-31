#include <iostream>
#include <algorithm>
#include <string>

using ll = unsigned long long;

const ll inf = 2000000000000000000;

int T;
ll ans;
std::string s;

ll gao(std::string y, int x) {
	ll y_value = std::stoll(y);
	ll res = inf;
	ll fuck = std::stoull(y.substr(0, x));
	std::string temp = "";
	while (temp.length() < y.length()) {
		temp += std::to_string(fuck);
		fuck++;
	}
//	std::cerr << temp << '\n';
	if (std::stoll(temp) > y_value) {
		res = std::min(res, std::stoull(temp));
	}
	temp = "";
	fuck = std::stoll(y.substr(0, x)) + 1;
	while (temp.length() < y.length()) {
		temp += std::to_string(fuck);
		fuck++;
	}
//	std::cerr << temp << '\n';
	if (std::stoll(temp) > y_value) {
		res = std::min(res, std::stoull(temp));
	}
	return res;
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> T;
	for (int CAS = 1; CAS <= T; CAS++) {
		std::cin >> s;
		ans = inf;
		for (int i = 1; i + i <= s.length(); i++) {
			ans = std::min(ans, gao(s, i));
		}
		std::cout << "Case #" << CAS << ": " << ans << '\n';
	}
}