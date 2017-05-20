#include <iostream>
#include <algorithm>

int a[110];

int main(int argc, char *argv[]) {  
	int n;
	std::cin >> n; 
	int m = -1;  
	for(int i = 0; i < n; i++) {  
		std::cin >> a[i];  
		m = std::max(m,a[i]);  
	}  
	long long ans = 0;  
	for(int i = 0; i < n; i++) {  
		ans += m - a[i];  
	}  
	std::cout << ans;  
	return 0;
}

