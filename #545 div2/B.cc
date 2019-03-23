#include <iostream>
#include <string>

int n;
std::string s1, s2;

int a[3][3];

int main(int argc, char *argv[]) {  
	std::cin >> n >> s1 >> s2;
	a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;
	for (int i = 0; i < n; i++) {
		a[int(s1[i]-'0')][int(s2[i]-'0')]++;
	}
	int x = 0, y = 0, z = 0;
	bool yes = 0;
	for (; x <= a[1][0] && x <= n/2; x++) {
		for (; y <= a[1][1] && x + y <= n/2; y++) {
			z = x + 2 * y - a[1][1];
			if (z >= 0 && z <= a[0][1] && n/2-x-y-a[0][1]+z >= 0 && n/2-x-y-a[0][1]+z <= a[0][0]) {
				yes = 1;
				goto outt;
			}
		}
	}
	outt:
	if (!yes) {
		std::cout << "-1";
		exit(0);
	}
	int aa, bb, cc, dd;
	cc = x;
	dd = y;
	bb = a[0][1]-z;
	aa = n/2-x-y-bb;
	int cnt1, cnt2, cnt3, cnt4;
	cnt1 = cnt2 = cnt3 = cnt4 = 0;
	for (int i = 0; i < n; i++) {
		if (s1[i] == '0' && s2[i] == '0') {
			if (cnt1 < aa) {
				std::cout << i+1 << " ";
				cnt1++;
			}
		} else if (s1[i] == '0' && s2[i] == '1') {
			if (cnt2 < bb) {
				std::cout << i+1 << " ";
				cnt2++;
			}
		} else if (s1[i] == '1' && s2[i] == '0') {
			if (cnt3 < cc) {
				std::cout << i+1 << " ";
				cnt3++;
			}
		} else {
			if (cnt4 < dd) {
				std::cout << i+1 << " ";
				cnt4++;
			}
		} 
	}
}