#include <iostream>
#include <string>

std::string s;
int n;

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'n') {
			cnt++;
		}
	}
	int x = (n - 3 * cnt) / 4;
	for (int i = 0; i < cnt; i++) {
		std::cout << "1 ";
	}
	for (int i = 0; i < x; i++) {
		std::cout << "0 ";
	}
}