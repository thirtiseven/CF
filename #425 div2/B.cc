#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::string good_letter, pattern;
	std::set<char> letter_set;
	letter_set.clear();
	std::cin >> good_letter >> pattern;
	int plen = pattern.length();
	for(int i = 0; i < good_letter.length(); i++) {
		letter_set.insert(good_letter[i]);
	}
	int n;
	std::cin >> n;
	bool flag = 0, star = 0;
	for(int i = 0; i < n; i++) {
		std::string s;
		s.clear();
		std::cin >> s;
		flag = 0;
		int len = s.length();
		if(pattern.length() - 1 > len) {
			std::cout << "NO\n";
			continue;
		}
		int j = 0;
		for(int i = 0; i < plen; i++) {
			//std::cout << i << " " << j << "\n";
			if(pattern[i] == '*') {
				star = 1;
				int l = len - plen;
				if(l == -1) {
					continue;
				}
				if(l >= 1) {
					int k = j;
					for(; k <= j + l; k++) {
						if(letter_set.count(s[k]) == 1) {
							std::cout << "NO\n";
							flag = 1;
							goto outside;
						}
					}
					j += l + 1;
					//std::cout << i << " " << j << "\n";
					continue;
				}
			} 
			//std::cout << i << " " << j << "\n";
			if(pattern[i] == s[j]) {
				j++;
				continue;
			} else if(pattern[i] == '?' && letter_set.count(s[j]) == 1) {
				j++;
				continue;
			} else if(pattern[i] == '*' && letter_set.count(s[j]) == 0) {
				j++;
				continue;
			} else {
				std::cout << "no\n";
				flag = 1;
				break;
			}
		}
		if(j < len && !flag && !star) {
			std::cout << "No\n";
			flag = 1;
		}
		outside: 
		if(!flag) {
			std::cout << "YES\n";
		}	 
	}
	return 0;
}