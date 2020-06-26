#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

std::string s, t;
int n;
std::string x;
std::vector<int> ans;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> s >> t;
	if (s == t) {
		std::cout << "0\n";
		exit(0);
	}
	int one1 = 0, one2 = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			one1++;
		}
		if (t[i] == '1') {
			one2++;
		}
		if (s[i] != t[i]) {
			if (s[i] == '1') {
				x += "1";
			} else {
				x += "0";
			}
		}
	}
	if (one1 != one2) {
		std::cout << "-1\n";
		exit(0);
	}
	assert(x.length()%2==0);
	x += "x";
	int cur = 1;
	for (int i = 1; i < x.length(); i++) {
		if (x[i] == x[i-1]) {
			cur++;
		} else {
			ans.push_back(cur);
			cur = 1;
		}
	}
	std::cout << *std::max_element(ans.begin(), ans.end()) << '\n';
}