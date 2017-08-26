#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int x, y;
	std::cin >> x >> y;
	int a = y, b = y, c = y, cnt = 0;
	do {
		a = b + c - 1;
		std::swap(a, c);
		std::swap(a, b);
		cnt++;
		//std::cout << a << " " << b << " " << c << std::endl;
	} while(c < x);
	std::cout << cnt + 2;
	return 0;
}