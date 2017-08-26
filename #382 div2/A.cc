#include <iostream>
#include <string>
#include <cmath>

int main(int argc, char *argv[]) {  
	std::string box;
	int n, k;
	std::cin >> n >> k >> box;
	int g, t;
	for(int i = 0; i < n; i++) {
		if(box[i] == 'G') {
			g = i;
		} else if(box[i] == 'T') {
			t = i;
		}
	}
	int pos = g, dir = -1, flag = 0;
	if(g < t) {
		dir = 1;
		while(pos < t) {
			pos += k;
			if(pos > n) {
				break;
			}
			if(box[pos] == '#') {
				break;
			}
		}
		if(pos == t) {
			flag = 1;
		}
	} else {
		while(pos > t) {
			pos -= k;
			if(pos < 0) {
				break;
			}
			if(box[pos] == '#') {
				break;
			}
		}
		if(pos == t) {
			flag = 1;
		}
	}
	if(flag) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}