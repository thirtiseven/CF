#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>

const float eps = 0.01;

int check(int x, int y) {
	int c = int(sqrt(x*x+y*y)+eps);
	if (x*x+y*y==c*c) {
		return c;
	}
	return 0;
}

int gcd(int a, int b) { 
	int t;
	while(b != 0) { 
		t=a%b;
		a=b;
		b=t; 
	}
	return a; 
}

std::map<int, std::pair<int, int>> gougu; 

void init() {
	int res;
	for (int i = 1; i <= 1000; i++) {
		for (int j = i+1; j <= 1000; j++) {
			res = check(i, j);
			if (res) {
				gougu[res] = std::make_pair(i, j);
			}
			if (res > 1000) {
				continue;
			}
		}
	}
}

int main(int argc, char *argv[]) {  
	int a, b;
	init();
	std::cin >> a >> b;
	if (a > b) {
		std::swap(a, b);
	}
	int c = gcd(a, b);
	int aa = a/c;
	int bb = b/c;
	if (gougu.find(c) != gougu.end()) {
		int xx = gougu[c].first;
		int yy = gougu[c].second;
		std::cout << "YES\n";
		std::cout << "0 0\n" << xx*aa << ' ' << yy*aa << '\n' << yy*bb << " -" << xx*bb << '\n';
	} else {
		std::cout << "NO\n";
	}
}