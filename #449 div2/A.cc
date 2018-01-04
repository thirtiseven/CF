#include <iostream>
#include <string>

int main(int argc, char *argv[]) {  
	int m, n;
	std::cin >> n >> m;
	std::string s;
	std::cin >> s;
	int l, r;
	char c1, c2;
	for(int i = 0; i < m; i++) {
		std::cin >> l >> r >> c1 >> c2;
		for(int j = l-1; j <= r-1; j++) {
			if(s[j] == c1) {
				s[j] = c2;
			}
		}
	}	
	std::cout << s << std::endl;
	return 0;
}