#include <iostream>

int main(int argc, char *argv[]) {  
	long long n, k;
	std::cin >> n >> k;
	if((n/k)%2==1) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
	}
	return 0;
}