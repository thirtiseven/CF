#include <iostream>

int main(int argc, char *argv[]) {  
	long long n, x, d;
	char c;
	std::cin >> n >> x;
	long long ansc = 0;
	for(int i =0; i < n; i++) {
		std::cin >> c >> d;
		if(c == '+') {
			x += d;
		} else {
			if(x >= d) {
				x -= d;
			} else {
				ansc++;
			}
		}
	}
	std::cout << x << " " << ansc;
	return 0;
}