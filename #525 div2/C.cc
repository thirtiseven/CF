#include <iostream>

const int maxn = 2345;
const int upp = 1e6;
const int up2 = 9e5-10;

int main(int argc, char *argv[]) {  
	int n, a[maxn];
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::cout << n+1 << '\n';
	std::cout << "1 " << n << " " << upp << '\n';
	for (int j = 0; j < n; j++) {
		a[j] += upp;
	}
	std::cout << "1 " << n << " " << up2 << '\n';
	for (int j = 0; j < n; j++) {
		a[j] += up2;
	}
	int num;
	for (int i = n-2; i >= 0; i--) {
		if (a[i] >= a[i+1]) {
			num = a[i]/2+1;
			std::cout << "2 " << i+1 << " " << num << '\n';
			for (int j = 0; j <= i; j++) {
				a[j] %= num;
			}
		} else {
			num = a[i+1] - 1 - a[i];
			if ((a[i] + num)%2==0) num--;
			std::cout << "1 " << i+1 << " " << num << '\n';
			for (int j = 0; j <= i; j++) {
				a[j] += num;
			}
		}
		for (int i = 0; i < n; i++) {
			std::cerr << a[i] << " ";
		}
		std::cerr << "\n";
	}
}