#include <iostream>
#include <string>

int n, k;
std::string a, b, p;

bool gao() {
	for (int i = k; i < n; i++) {
		if (a[i%k] > a[i]) {
			return true;
		} else if (a[i%k] < a[i]) {
			return false;
		}	
	}
	return true;
}

int main(int argc, char *argv[]) {  
	std::cin >> n >> k >> a;
	p = a.substr(0, k);
	bool always9 = 1, got = 1;
	for (auto it: p) {
		if (it != '9') {
			always9 = 0;
			break;
		}
	}
	got = gao();
	if (!always9 && !got) {
		int c = k-1;
		while (p[c] == '9') {
			c--;
		}
		p[c] = char(p[c] + 1);
		for (int i = c+1; i < p.length(); i++) {
			p[i] = '0';
		}
	}
//	std::cout << p << '\n';
	std::cout << n << '\n';
	for (int i = 0; i < n; i++) {
		std::cout << p[i%k];
	}
	std::cout << '\n';
}