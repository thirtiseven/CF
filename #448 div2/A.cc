#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {  
	int n;
	int a[800];
	int aa=0, bb=0;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[n+i] = a[i];
	}
	int ans = 400;
	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; sum < 180; j=(j+1)%n) {
			sum += a[j];
			//std::cout << sum << ' ' << a[j] << '\n';
		}
		ans = std::min(ans, std::abs(sum-(360-sum)));
		//std::cout << ans << ' ' << std::abs(sum-(360-sum)) << " miaomiaomiao\n";
	}
	std::cout << ans << '\n'; 
}