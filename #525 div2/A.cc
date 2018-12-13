#include <iostream>

int main(int argc, char *argv[]) {  
	int x;
	std::cin >> x;
	for (int a = 1; a <= x; a++) {
		for (int b = 1; b <= x; b++) {
			if (a%b==0 && a*b>x && a/b < x) {
				std::cout << a << " " << b << '\n';
				exit(0);
			}
		}
	}
	std::cout << "-1\n";
}