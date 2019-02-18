#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	ll a, b, aa = 0, bb = 0;
	for (int i = 0; i < 2*n; i++) {
		std::cin >> a >> b;
		aa+=a;
		bb+=b;
	}
	std::cout << aa/n << " " << bb/n;
}