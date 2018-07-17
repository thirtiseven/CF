#include <iostream>

int main(int argc, char *argv[]) {  
	int n, d, x[123];
	std::cin >> n >> d;
	for (int i = 0; i < n; i++) {
		std::cin >> x[i];
	}
	int ans = 2;
	for (int i = 0; i < n-1; i++) {
		if (x[i+1]-x[i]>2*d) {
			ans+=2;
		} else if (x[i+1]-x[i]==2*d) {
			ans+=1;
		}
	}
	std::cout << ans;
}