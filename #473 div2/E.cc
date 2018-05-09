#include <iostream>
#include <cmath>

int main(int argc, char *argv[]) {  
	long long n;
	std::cin >> n;
	long long ans = 0;
	for (long long i=1; i<n; i*=2) {
		ans += ((n-i-1)/(2*i)+1)*i;
	}
	std::cout << ans;
}