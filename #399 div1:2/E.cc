#include <iostream>
int n;
int s[1000010], a[1000010], xo[1000010];

int main(int argc, char *argv[]) {  
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> s[i];
	}
	for(int i = 0; i < n; i++) {
		int j;
		for(j = 1; j <= 60; j++) {  
			s[i] -= j;  
			if(s[i] <= j) {
				break;  
			}
		} 
		a[i] = j;
	}
	int ans = a[0];
	for(int i = 1; i < n; i++) {
		ans ^= a[i];
	}
	if(ans) {
		std::cout << "NO";
	} else {
		std::cout << "YES";
	}
	return 0;
}