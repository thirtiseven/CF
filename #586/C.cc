#include <iostream>
#include <string>
#include <map>

int cnt[30];

int main(int argc, char *argv[]) {  
	std::string s;
	std::cin >> s;
	for (auto it: s) {
		if (cnt[it-'a'] > 0) {
			std::cout << "Ann\n";
		} else {
			std::cout << "Mike\n";
		}
		for (int i = int(it-'a')+1; i < 26; i++) {
			cnt[i]++;
		}
	}
}