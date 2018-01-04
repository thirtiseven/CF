#include <iostream>

int main(int argc, char *argv[]) {  
	int a, b, n;
	std::cin >> n >> a >> b;
	for(int i = 0; i <= n/a; i++) {
		if((n-i*a)%b==0) {
			std::cout << "YES\n" << i << " " << (n-i*a)/b << '\n';
			return 0;
		}
	}
	std::cout << "NO\n";
	return 0;
}