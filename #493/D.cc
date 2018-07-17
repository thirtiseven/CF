#include <iostream>

using ll = long long;

int main(int argc, char *argv[]) {  
	ll n;
	std::cin >> n;
	ll a[20] = {0,4,10,20,35,56,83,116,155,198,244,292,341,390,439,488,537,586,635,684 };
	if (n <= 15) {
		std::cout << a[n];
	} else {
		std::cout << a[15] + (n - 15) * 49;
	}
}