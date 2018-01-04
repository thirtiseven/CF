#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	long long n, temp, sum = 0, b[100010];
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> temp;
		sum += temp;
	}
	for(int i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::sort(b, b+n);
	std::cout << ((b[n-1] + b[n-2] >= sum)?"YES\n":"NO\n");
	return 0;
}