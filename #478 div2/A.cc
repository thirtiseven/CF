#include <iostream>
#include <string>
#include <set>

const int maxn = 1e4+9;
std::string s[maxn];
std::string t = "0000000000000000000000000000";
std::set<std::string> ss; 

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> s[i];
		std::string aa = t;
		for (int j = 0; j < s[i].length(); j++) {
			aa[int(s[i][j]-'a')] = '1';
		}
//		std::cout << aa << '\n';
		ss.insert(aa);
	}
	std::cout << ss.size();
}