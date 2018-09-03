#include <iostream>

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n;
	int ans = 0;
	while (n) {
		n/=2;
		ans++;
	}
	std::cout << ans;
}