#include <iostream>
#include <string>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int num[4] = {0, 0, 0, 0};
	std::string s;
	int n, b;
	std::cin >> n >> s;
	b = n/3;
	for (auto it: s) {
		num[int(it-'0')]++;
	}
	for (int i = 0; i < 3; i++) {
		num[i] = num[i]-b;
	}
	int ab = 0, ba = 0, ac = 0, ca = 0, bc = 0, cb = 0;
	if (-num[0] == num[1] + num[2] && num[1] * num[2] >= 0) {
		if (num[0] > 0) {
			ab = -num[1];
			ac = -num[2];
		} else {
			ba = num[1];
			ca = num[2];
		}
	} else if (-num[1] == num[0] + num[2] && num[0] * num[2] >= 0) {
		if (num[1] > 0) {
			ba = -num[0];
			bc = -num[2];
		} else {
			ab = num[0];
			cb = num[2];
		}
	} else if (-num[2] == num[0] + num[1] && num[0] * num[1] >= 0) {
		if (num[2] > 0) {
			ca = -num[0];
			cb = -num[1];
		} else {
			ac = num[0];
			bc = num[1];
		}
	}
	std::cout << num[0] << " " << num[1] << " " << num[2] << '\n';
	std::cout << ab << " " << ba << " " << ac << " " << ca << " " << bc << " " << cb << "\n";
	for (int i = 0; i < n; i++) {
		if (s[i] == '2' && ca > 0) {
			s[i] = '0';
			ca--;
		} else if (s[i] == '2' && cb > 0) {
			s[i] = '1';
			cb--;
		} else if (s[i] == '1' && ba > 0) {
			s[i] = '0';
			ba--;
		}
	}
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '1' && bc > 0) {
			s[i] = '2';
			bc--;
		} else if (s[i] == '0' && ac > 0) {
			s[i] = '2';
			ac--;
		} else if (s[i] == '0' && ab > 0) {
			s[i] = '1';
			ab--;
		}
 	}
	std::cout << s << '\n';
}