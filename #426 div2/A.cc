#include <iostream>

int main(int argc, char *argv[]) {  
	char a, b;
	int m, n;
	int c;
	std::cin >> a >> b;
	std::cin >> c;
	
	if(a == 'v') {
		m = 1;
	}
	if(a == '<') {
		m = 2;
	}
	if(a == '^') {
		m = 3;
	}
	if(a == '>') {
		m = 0;
	}
	if(b == 'v') {
		n = 1;
	}
	if(b == '<') {
		n = 2;
	}
	if(b == '^') {
		n = 3;
	}
	if(b == '>') {
		n = 0;
	}
	if(m+n == 4 || m+n == 2) {
		std::cout << "undefined";
	} else if((m + c) % 4 == n){
		std::cout << "cw";
	} else {
		std::cout << "ccw";
	}
	return 0;
}