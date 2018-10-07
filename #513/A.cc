#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int n, cnt = 0;
	std::string s;
	std::cin >> n >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '8') {
			cnt++;
		}
	}
	std::cout << std::min(cnt, n/11);
}