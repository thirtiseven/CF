#include <iostream>
#include <string>
#include <algorithm>

int n;
std::string s;
int ans = 2e5+1;
int now;
std::string cas;

void solve(std::string pattern) {
	now = 0;
	for (int i = 0; i < n; i+=3) {
		if (s[i] != pattern[0]) now++;
	}
	for (int i = 1; i < n; i+=3) {
		if (s[i] != pattern[1]) now++;
	}
	for (int i = 2; i < n; i+=3) {
		if (s[i] != pattern[2]) now++;
	}
	if (now < ans) {
		ans = now;
		cas = pattern;
	}
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> s;
	solve("RGB");
	solve("RBG");
	solve("BRG");
	solve("BGR");
	solve("GBR");
	solve("GRB");
	std::cout << ans << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << cas[i%3];
	}
}