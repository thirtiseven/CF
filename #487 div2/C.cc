#include <iostream>
#include <string>

std::string s[50];
std::string aa = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
std::string bb = "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB";
std::string ba = "BABABABABABABABABABABABABABABABABABABABABABABABABA";

int nowx, nowy;

void nextt() {
	nowy += 2;
	if (nowy >= 50) {
		nowy = 1;
		nowx += 2;
	}
}

int main(int argc, char *argv[]) {  
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	for (int i = 0; i < 9; i++) {
		s[i] = bb;
	}
	for (int i = 9; i < 50; i++) {
		s[i] = aa;
	}
	s[8][0] = 'B';
	a--, b--;
	int sum = b+c+d;
	if (a == 0) {
		;
	} else if (a <= 25) {
		for (int i = 1; i < 50; i += 2) {
			s[1][i] = 'A';
			a--;
			if(a <= 0) break;
		}
	} else if (a <= 50) {
		s[1] = ba;
		a -= 25;
		for (int i = 1; i < 50; i += 2) {
			s[3][i] = 'A';
			a--;
			if(a <= 0) break;
		}
	} else if (a <= 75) {
		s[1] = ba;
		s[3] = ba;
		a -= 50;
		for (int i = 1; i < 50; i += 2) {
			s[5][i] = 'A';
			a--;
			if(a <= 0) break;
		}
	} else if (a <= 100) {
		s[1] = ba;
		s[3] = ba;
		s[5] = ba;
		a -= 75;
		for (int i = 1; i < 50; i += 2) {
			s[7][i] = 'A';
			a--;
			if(a <= 0) break;
		}
	}
	nowx = 10, nowy = 1;
	for (int i = 0; i < b; i++) {
		s[nowx][nowy] = 'B';
		nextt();
	}
	for (int i = 0; i < c; i++) {
		s[nowx][nowy] = 'C';
		nextt();
	}
	for (int i = 0; i < d; i++) {
		s[nowx][nowy] = 'D';
		nextt();
	}
	std::cout << "50 50\n";
	for (int i = 0; i < 50; i++) {
		std::cout << s[i] << '\n';
	}
}