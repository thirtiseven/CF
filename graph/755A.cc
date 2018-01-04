#include <iostream>
#include <cmath>

const int maxn = 1000009;

int main(int argc, char *argv[]) {  
	bool prime_or_not[maxn];
	for (int i = 2; i <= int(sqrt(maxn)); i++) {
		if (!prime_or_not[i]) {
	    	for (int j = i * i; j <= maxn; j = j+i) {
				prime_or_not[j] = 1;
			}
		}
	}
	int n;
	std::cin >> n;
	for (int i = 1; i <= 1000; i++) {
		if(prime_or_not[n*i+1]) {
			std::cout << i << std::endl;
			break;
		}
	}
	return 0;
}