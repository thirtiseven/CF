#include <iostream>
#include <string>

int t;
std::string s[10];

void trans(char &c) {
	int x = int(c-'0');
	x = (x+3)%9+1;
	c = char('0'+x);
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); 
	std::cin >> t;
	while (t--) {
		for (int i = 0; i < 9; i++) {
			std::cin >> s[i];
		}
		trans(s[0][0]);
		trans(s[1][3]);
		trans(s[2][6]);
		
		trans(s[3][1]);
		trans(s[4][4]);
		trans(s[5][7]);
		
		trans(s[6][2]);
		trans(s[7][5]);
		trans(s[8][8]);
		for (int i = 0; i < 9; i++) {
			std::cout << s[i] << '\n';
		}
	}
}