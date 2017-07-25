#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::string good_letter, pattern;
	std::set<char> letter_set;
	std::cin >> good_letter >> pattern;
	for(int i = 0; i < good_letter.length(); i++) {
		letter_set.insert(good_letter[i]);
	}
	int n;
	std::cin >> n;
	bool flag;
	for(int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		flag = 0;
		int len = s.length();
		if(pattern.length() - 1 > s.length()) {
			std::cout << "NO\n";
			continue;
		}
		int j = 0;
		for(int i = 0; i < len; i++) {
			//std::cout << i << " " << j << "\n";
			if(pattern[i] == '*') {
				int l = len - pattern.length();
				if(l >= 1) {
					int k;
					for(k = j; k <= j + l; k++) {
						if(letter_set.find(s[k]) == letter_set.end()) {
							continue;
						} else {
							std::cout << "NO\n";
							flag = 1;
							goto outside;
						}
					}
					i++;
					j += (l + 1);
				}
				continue;
			} else if(pattern[i] == s[j]) {
				j++;
				continue;
			} else if(pattern[i] == '?' && letter_set.find(s[j]) != letter_set.end()) {
				j++;
				continue;
			} else if(pattern[i] == '*' && letter_set.find(s[j]) == letter_set.end()) {
				j++;
				continue;
			} else {
				std::cout << "no\n";
				flag = 1;
				break;
			}
		}
		outside: if(!flag) {
			std::cout << "YES\n";
		}	 
	}
	return 0;
}