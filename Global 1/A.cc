#include <iostream>

const int maxn = 1e5+7;

int main(int argc, char *argv[]) {  
	int b, k;
	int a[maxn];
	int now = 0;
	std::cin >> b >> k;
	for (int i = 0; i < k; i++) {
		std::cin >> a[i];
		now += a[i]%2;
	}
	if ((b%2==1 && now%2==1) || (b%2==0 && a[k-1]%2==1)) {
		std::cout << "odd\n";
	} else {
		std::cout << "even\n";
	}
}