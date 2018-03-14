#include <iostream>
#include <map>
#include <string>

std::map<std::string, std::string> ip_s;

int main(int argc, char *argv[]) {  
	int n, m;
	std::cin >> n >> m;
	std::string s1, s2;
	for (int i = 0; i < n; i++) {
		std::cin >> s1 >> s2;
		ip_s[s2] = s1;
	}
	for (int i = 0; i < m; i++) {
		std::cin >> s1 >> s2;
		s2.erase(s2.length()-1, 1);
		std::cout << s1 << " " << s2 << "; #" << ip_s[s2] << '\n';
	}
	return 0;
}