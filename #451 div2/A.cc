#include <iostream>

int main(int argc, char *argv[]) {  
	long long n;
	std::cin >> n;
	long long a = n-n%10;
	if(n%10 <= 5) {
		std::cout << a << '\n';
	} else {
		std::cout << a+10 << '\n';
	}
	return 0;
}