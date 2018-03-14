#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n, k;
	std::string s, ans;
	std::vector<char> ss;
	std::cin >> n >> k >> s;
	for (int i = 0; i < s.length(); i++) {
		ss.push_back(s[i]);
	}
	std::sort(ss.begin(), ss.end());
	if (k > n) {
		std::cout << s;
		for (int i = 0; i < k-n; i++) {
			std::cout << ss[0];
		}
	} else {
		int endd = k-1;
		while(s[endd] == ss[s.length()-1]) {
			endd--;
		}
		for (int i = 0; i < endd; i++) {
			std::cout << s[i];
		}
		for (int i = 0; i < s.length(); i++) {
			if (ss[i] > s[endd]) {
				std::cout << ss[i];
				break;
			}
		}
		for (int i = endd; i < k-1; i++) {
			std::cout << ss[0];
		}
	}
}