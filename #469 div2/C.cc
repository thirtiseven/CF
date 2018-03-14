#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>

const int maxn = 2000000;

bool vis[maxn];
std::multiset<int> d;

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	int zerobefore = 0, consismax = 1, consis = 1, zeroafter = 0, onecnt = 0, tempcnt = 0;
	bool yes = 1;
	if (s[0] == '1') {
		std::cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') {
			zerobefore++;
		} else {
			onecnt++;
			if (onecnt > zerobefore) {
				std::cout << "-1\n";
				return 0;
			}
			if (s[i-1] == '1') {
				consis++;
				consismax = std::max(consis, consismax);
				d.insert(consis);
				consis = 0;
			} else {
				consis++;
			}
		}
	}
	for (int i = s.length()-1; i >= 0; i--) {
		if (s[i] == '0') {
			zeroafter ++;
		} else {
			tempcnt ++;
			if (tempcnt > consismax) {
				break;
			}
		}
	}
	if (consismax > zeroafter) {
		std::cout << "-1\n";
		return 0;
	}
	std::cout << consismax << " " << zeroafter << '\n';
	int k = consismax + (zeroafter - consismax);
	std::cout << k << '\n';
	int sum = 0;
	for (int i = 1; i <= consismax; i++) {
		sum += d.count(i);
	}
	
}