#include <iostream>

int main(int argc, char *argv[]) {  
	long long n, k, a[110];
	bool flag = 1;
	std::cin >> n >> k;
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		sum += a[i];
		if(sum < 8) {
			k -= sum;
			sum = 0;
		} else {
			k -= 8;
			sum -= 8;
		}		
		if(k <= 0) {
			std::cout << i+1 << "\n";
			flag = 0;
			break;	
		}
	}
	if(flag) {
		std::cout << "-1\n";
	}
	return 0;
}