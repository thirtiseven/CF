#include <iostream>

const int maxn = 200000+9;

int main(int argc, char *argv[]) {  
	long long n, a[maxn];
	std::cin >> n;
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
	}
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i];
		if (ans >= (sum+1)/2) {
			std::cout << i+1;
			break;
		}
	}
}